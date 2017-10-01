/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:01:39 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/01 17:07:11 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ms_print_exit_statut(char *exec, unsigned char status)
{
	ft_printf("%lu %u %s\n", status, WTERMSIG(status), exec);
}

void			ms_print_cmd_not_found(char *name)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(name, 2);
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
		if (!*exec)
			(void)exec;
		else if ((f = ms_check_is_builtin(*exec)))
			f(exec, env);
		else if ((path = ms_check_bin(*exec, *env)))
		{
			if ((ret = ms_exec_bin(path, exec, env)))
				ms_print_exit_statut(*exec, ret);
		}
		else
			ms_print_cmd_not_found(*exec);
	}
}
