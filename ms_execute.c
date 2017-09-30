/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:01:39 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/30 20:38:28 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ms_print_exit_statut(char *exec, unsigned char status)
{

}

void		ms_execute(char ***cmd, char **env)
{
	int				i;
	char			**exec;
	unsigned char	ret;

	i = -1;
	while ((exec = *(cmd + ++i)))
	{
		if (ms_check_is_builtin(exec, env))
			ms_builtin_wrap(exec, env);
		else if (ms_check_bin(exec, env))
			if ((ret = ms_exec_bin(exec, env)))
				ms_print_exit_statut(*exec, ret);
	}
}
