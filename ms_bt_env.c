/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_bt_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 19:16:38 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/18 11:41:08 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned char	ms_bt_env_print(char ***env)
{
	int		i;

	i = 0;
	if (!env || !(*env))
		return (1);
	while (*(*env + i))
		ft_putendl(*(*env + i++));
	return (0);
}

unsigned char			ms_bt_env(char **cmd, char ***env)
{
	int		len;
	char	noenv;

	noenv = 0;
	len = ft_tablen((void**)cmd);
	if (len <= 1)
		return (ms_bt_env_print(env));
	else if (**(cmd + 1) == '-' && *(*(cmd + 1) + 1))
	{
		if (!ft_strcmp(*(cmd + 1), "-i") && (cmd++ || 1))
			noenv = 1;
		else
		{
			ft_putstr_fd("env: illegal option -- ", 2);
			ft_putendl_fd((*(cmd + 1) + 1), 2);
			ft_putendl_fd("usage: env [-i] name_exec", 2);
			return (1);
		}
	}
	cmd++;
	return (ms_execute(cmd, env, (noenv) ? 1 : 0));
}
