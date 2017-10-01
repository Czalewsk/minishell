/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:01:28 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/01 16:27:09 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		*ms_check_is_builtin(char *cmd)
{
	const t_ms_builtin	list_bt[] = {{ "exit", &ms_bt_exit}, {"", NULL}};
	int					i;

	i = -1;
	if (!cmd)
		return (NULL);
	while (list_bt[++i].f)
		if (!ft_strcmp(cmd, list_bt[i].name))
			return (list_bt[i].f);
	return (NULL);
}
