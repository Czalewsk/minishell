/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:01:39 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/17 12:49:19 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned char	ms_print_exit_statut(char *exec, unsigned char status,
		t_ms_process *info)
{
	int ret;

	ret = info->ret;
	if (WIFEXITED(ret) && WEXITSTATUS(ret) != UCHAR_MAX)
		return (status);
	else if (WEXITSTATUS(ret) == UCHAR_MAX)
	{
		ft_putstr_fd("Minishell: Fail to execve: ", 2);
		ft_putendl_fd(exec, 2);
	}
	else
		ft_printf("Process[%lu] killed by signal:%u  %s\n",
				info->pid, WTERMSIG(info->ret), exec);
	return (status);
}

unsigned char	ms_print_cmd_not_found(char *name)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(name, 2);
	return (1);
}

unsigned char	ms_exec_bin(char *path, char **exec, char ***env,
		t_ms_process *info)
{
	pid_t			father;

	father = fork();
	if (!father)
	{
		execve(path, exec, *env);
		exit(-1);
	}
	else if (father > 0)
		info->pid = wait(&info->ret);
	return (WIFEXITED(info->ret) ? WEXITSTATUS(info->ret) : 1);
}

unsigned char	ms_execute(char ***cmd, char ***env, t_ms_process *info)
{
	int				i;
	char			**exec;
	char			*path;
	unsigned char	ret;
	unsigned char	(*f)(char **, char ***);

	i = -1;
	ret = 0;
	while ((exec = *(cmd + ++i)))
	{
		if (!*exec)
			ret = 0;
		else if ((f = ms_check_is_builtin(*exec)))
			ret = f(exec, env);
		else if ((path = ms_check_bin(*exec, *env)))
		{
			if ((ret = ms_exec_bin(path, exec, env, info)))
				ret = ms_print_exit_statut(*exec, ret, info);
			ft_strdel(&path);
		}
		else
			ret = ms_print_cmd_not_found(*exec);
	}
	return (ret);
}
