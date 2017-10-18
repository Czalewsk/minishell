/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 12:30:03 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/18 12:47:30 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ms_env_mod(char ***env, char *key, char *value)
{
	int		i;
	char	*line;
	int		size_key;

	if (!env || !*env)
		return ;
	i = -1;
	size_key = ft_strlen(key);
	while (*(*env + ++i))
	{
		line = *(*env + i);
		if (ft_strcmp(line, key) == '=' && *(line + size_key) == '=')
		{
			ft_memdel((void**)*env + i);
			*(*env + i) = ft_strxjoin(3, key, "=", value ? value : "");
			break ;
		}
	}
}

