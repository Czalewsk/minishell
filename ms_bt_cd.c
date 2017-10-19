/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_bt_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:45:17 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/19 13:57:43 by czalewsk         ###   ########.fr       */
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

unsigned char			ms_bt_cd(char **cmd, char ***env)
{
	int				len;
	unsigned char	ret;

	(void)env;
	len = ft_tablen((void**)cmd);
	if (len > 2)
	{
		ft_putstr_fd("cd: string not in pwd: ", 2);
		ft_putendl_fd(*(cmd + 1), 2);
		return (1);
	}
	if ((len != 1) && (ret = chdir(*(cmd + 1))))
	{
		if (access(*(cmd + 1), X_OK))
			ft_putstr_fd("cd: permission denied: ", 2);
		else
			ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(*(cmd + 1), 2);
	}
	else if (len == 1)
		ret = ms_bt_cd_home(*env);
	return (ret);
}
