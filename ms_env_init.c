/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 09:44:24 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/30 17:31:01 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ms_env_init(char ***env)
{
	int		size;
	int		i;
	char	**tab;

	i = -1;
	size = ft_tablen((void**)*env);
	tab = ft_memalloc(sizeof(*tab) * (size + 1));
	while (++i < size)
		*(tab + i) = ft_strdup(*(*env + i));
}
