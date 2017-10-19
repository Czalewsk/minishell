/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:01:39 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/19 20:21:36 by czalewsk         ###   ########.fr       */
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

	g_prpt_already = 1;
	father = fork();
	if (!father)
	{
		execve(path, exec, (env ? *env : NULL));
		exit(-1);
	}
	else if (father > 0)
		info->pid = wait(&info->ret);
	g_prpt_already = 0;
	return (WIFEXITED(info->ret) ? WEXITSTATUS(info->ret) : 1);
}

unsigned char	ms_execute(char **exec, char ***env, char noenv)
{
	char			*path;
	unsigned char	(*f)(char **, char ***);
	unsigned char	ret;
	t_ms_process	info;

	if (!exec || !*exec)
		ret = (exec ? 0 : 1);
	else if ((f = ms_check_is_builtin(*exec)))
		ret = f(exec, (noenv ? NULL : env));
	else if (ms_check_exec_path(*exec) == 1)
	{
		if ((ret = ms_exec_bin(*exec, exec, env, &info)))
			ret = ms_print_exit_statut(*exec, ret, &info);
	}
	else if ((path = ms_check_bin(*exec, (env ? *env : NULL))))
	{
		if ((ret = ms_exec_bin(path, exec, (noenv ? NULL : env), &info)))
			ret = ms_print_exit_statut(*exec, ret, &info);
		ft_strdel(&path);
	}
	else
		ret = ms_print_cmd_not_found(*exec);
	return (ret);
}

unsigned char	ms_mult_execute(char ***cmd, char ***env)
{
	int						i;
	char					**exec;
	static unsigned char	ret;

	i = -1;
	while ((cmd + ++i) && (exec = *(cmd + i)))
		ret = ms_execute(exec, env, 0);
	return (ret);
}
