/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:01:39 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/30 20:13:19 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		ms_execute(char ***cmd, char **env)
{
	int		i;
	int		j;
	char	**exec;
	

	i = -1;
	j = -1;
	while ((exec = *(cmd + ++i)))
	{
		if (ms_check_is_builtin(exec, env))
			ms_builtin_wrap(exec, env);
		else if (ms_check_bin(exec, env))
			ms_exec_bin(exec, env);
	}
}
