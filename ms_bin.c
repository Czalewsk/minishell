/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:44:34 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/30 23:17:32 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*ms_get_all_path(char **env)
{
	char	*all_path;

	if (!(all_path = ms_env_value("PATH", 4, env)))
		return (NULL);
	return (ft_strsplit_lst(all_path, ':'));
}

char		*ms_check_bin(char *exec, char **env)
{
	t_list	*list_path;
	t_list	*cur;
	char	*path;

	if (!(list_path = ms_get_all_path(env)))
		return (NULL);
	cur = list_path;
	while (cur)
	{
		path = ft_strjoin(cur->content, exec);
		
	}
	return (NULL);
}
