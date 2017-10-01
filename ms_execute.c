/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:01:39 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/01 15:17:02 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ms_print_exit_statut(char *exec, unsigned char status)
{
	ft_printf("%lu %u %s\n", status, WTERMSIG(status), exec);
}

unsigned char	ms_exec_bin(char *path, char **exec, char ***env)
{
	pid_t		father;
	int			ret;

	father = fork();
	if (!father)
	{
		execve(path, exec, *env);
		exit (-1);
	}
	else if (father > 0)
		wait(&ret);
	return (WIFEXITED(ret) && WEXITSTATUS(ret) != UCHAR_MAX &&
			!WIFSIGNALED(ret) ? 0 : ret);
}

void			ms_execute(char ***cmd, char ***env)
{
	int				i;
	char			**exec;
	char			*path;
	unsigned char	ret;
	unsigned char	(*f)(char **, char ***);

	i = -1;
	while ((exec = *(cmd + ++i)))
	{
		if ((f = ms_check_is_builtin(*exec)))
			f(exec, env);
		else if ((path = ms_check_bin(*exec, *env)))
			if ((ret = ms_exec_bin(path, exec, env)))
				ms_print_exit_statut(*exec, ret);
	}
}
