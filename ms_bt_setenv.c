/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_bt_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:49:09 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/18 15:25:50 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned char	env_usage(int i)
{
	if (i)
		ft_putendl_fd("Too many arguments", 2);
	else
		ft_putendl_fd("usage: setenv variable_name [variable_value]", 2);
	return (1);
}

unsigned char	ms_bt_setenv(char **cmd, char ***env)
{
	int		len;

	len = ft_tablen((void**)cmd);
	if (len < 2 || len > 3)
		return(env_usage(len > 3 ? 1 : 0));
	if (!env || !*env)
		return (0);
	if (!ms_env_value(*(cmd + 1), ft_strlen(*(cmd + 1)), *env))
		ms_env_add(env, *(cmd + 1), *(cmd + 2));
	else
		ms_env_mod(env, *(cmd + 1), *(cmd + 2));
	return (0);
}
