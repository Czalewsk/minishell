/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:56:14 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/30 22:19:08 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ms_env_value(char *name, int size_name, char **env)
{
	int		i;
	char	*line;

	i = -1;
	if (!env)
		return (NULL);
	while (*(env + ++i))
	{
		line = *(env + i);
		if (ft_strcmp(line, name) == '=' && *(line + size_name) == '=')
			return (line + size_name + 1);
	}
	return (NULL);
}