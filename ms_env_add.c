/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 12:13:52 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/18 12:36:23 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ms_env_add(char ***env, char *key, char *value)
{
	int		len;
	char	**new;

	len = ft_tablen((void**) *env);
	new = ft_memalloc((len + 2) * sizeof(char**));
	ft_memcpy(new, *env, len * sizeof(char**));
	*(new + len) = ft_strxjoin(3, key, "=", value);
	ft_memdel((void**)env);
	*env = new;
}
