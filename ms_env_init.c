/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 09:44:24 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/01 19:06:43 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ms_free_env(char ***env)
{
	static	char	***addr_env;
	int				i;

	if (!addr_env)
	{
		addr_env = env;
		return ;
	}
	i = -1;
	while (*(*addr_env + ++i))
		ft_strdel(*addr_env + i);
	ft_memdel((void**)addr_env);
	get_next_line(-2, NULL);
}

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
	*env = tab;
	ms_free_env(env);
}
