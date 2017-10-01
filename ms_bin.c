/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:44:34 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/01 14:50:46 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ms_path_del(void *content, size_t size)
{
	(void)size;
	ft_strdel((char **)&content);
}

void		ms_bin_error(char *exec)
{
	ft_putstr_fd("Minishell: permission denied: ", 2);
	ft_putendl_fd(exec, 2);
}

static char	ms_check_exec_path(char *path)
{
	struct stat		info;
	int				ret;

	if (stat(path, &info))
		return (0);
	ret = 0;
	if (S_ISREG(info.st_mode))
		ret = -1;
	if (ret == -1 && info.st_mode & 0111)
		ret = 1;
	return (ret);
}

t_list		*ms_get_all_path(char **env)
{
	char	*all_path;

	if (!(all_path = ms_env_value("PATH", 4, env)))
		return (NULL);
	return (ft_strsplit_lst(all_path, ':'));
}

char		*ms_check_bin(char *exec, char **env)
{
	t_list	*list_path;
	t_list	*cur;
	char	*path;
	char	ret;
	char	error;

	if (!(list_path = ms_get_all_path(env)))
		return (NULL);
	cur = list_path;
	while (cur)
	{
		path = ft_strxjoin(3, cur->content, "/", exec);
		if ((ret = ms_check_exec_path(path)) == 1)
			break ;
		else if (ret)
			error = -1;
		ft_strdel(&path);
		cur = cur->next;
	}
	if (ret != 1 && error == -1)
		ms_bin_error(exec);
	ft_lstdel(&list_path, &ms_path_del);
	return (path);
}
