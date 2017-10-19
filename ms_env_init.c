/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 09:44:24 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/19 21:45:27 by czalewsk         ###   ########.fr       */
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
	char	*shlvl;

	i = -1;
	size = (env ? ft_tablen((void**)*env) : 0);
	tab = ft_memalloc(sizeof(*tab) * (size + 1));
	while (++i < size)
		*(tab + i) = ft_strdup(*(*env + i));
	*env = tab;
	ms_free_env(env);
	if ((shlvl = ms_env_value("SHLVL", 5, *env)))
	{
		ms_bt_setenv((char*[4]){"setenv", "SHLVL",
				(shlvl = ft_itoa(ft_atoi(shlvl) + 1))}, env);
		ft_strdel(&shlvl);
	}
	else
		ms_bt_setenv((char*[4]){"setenv", "SHLVL", "1"}, env);
}
