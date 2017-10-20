/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_bt_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:45:17 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/20 10:08:07 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned char	ms_bt_cd_home(char **env)
{
	char			*home;
	unsigned char	ret;

	if (!(home = ms_env_value("HOME", 4, env)))
	{
		ft_putendl_fd("No home directory.", 2);
		return (1);
	}
	if ((ret = chdir(home)))
		ft_putendl_fd("Can't change to home directory.", 2);
	return (ret);
}

static void				ms_bt_cd_pwd(char ***env, char *new_value,
		char *old_value)
{
	ms_bt_setenv((char*[4]){"setenv", "OLDPWD", old_value, NULL}, env);
	ms_bt_setenv((char*[4]){"setenv", "PWD", new_value, NULL}, env);
}

static void				ms_print_error(char *path)
{
	struct stat info;

	stat(path, &info);
	if (access(path, F_OK))
		ft_putstr_fd("cd: no such file or directory: ", 2);
	else if (access(path, X_OK) && (info.st_mode & S_IFMT) == S_IFDIR)
		ft_putstr_fd("cd: permission denied: ", 2);
	else
		ft_putstr_fd("cd: not a directory: ", 2);
	ft_putendl_fd(path, 2);
}

static unsigned char	ms_bt_cd_minus(char *oldpwd)
{
	unsigned char	ret;

	if (!oldpwd && (ret = 1))
		ft_putendl_fd("cd: OLDPWD is not set.", 2);
	else if ((ret = chdir(oldpwd)))
		oldpwd && ft_strlen(oldpwd) ? ms_print_error(oldpwd) :
			ft_putendl_fd("cd: OLDPWD is not set.", 2);
	return (ret);
}

unsigned char			ms_bt_cd(char **cmd, char ***env)
{
	int				len;
	unsigned char	ret;
	char			*path;

	path = NULL;
	len = ft_tablen((void**)cmd);
	if (len > 2)
	{
		ft_putstr_fd("cd: string not in pwd: ", 2);
		ft_putendl_fd(*(cmd + 1), 2);
		return (1);
	}
	if (len > 1 && !ft_strcmp(*(cmd + 1), "-"))
		ret = ms_bt_cd_minus(ms_env_value("OLDPWD", 6, env ? *env : NULL));
	else if ((len > 1) && (ret = chdir(*(cmd + 1))))
		ms_print_error(*(cmd + 1));
	else if (len == 1)
		ret = ms_bt_cd_home(env ? *env : NULL);
	if (!ret)
		ms_bt_cd_pwd(env, (len == 1 ? ms_env_value("HOME", 4, *env) :
					(path = getcwd(path, 0))), ms_env_value("PWD", 3, *env));
	ft_strdel(&path);
	return (ret);
}
