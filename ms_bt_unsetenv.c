/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_bt_unsetenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 12:50:10 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/18 15:24:12 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned char	env_usage(void)
{
	ft_putendl_fd("usage: unsetenv variable_name [variable_name]...", 2);
	return (1);
}

char					ms_env_index(char **env, char *key)
{
	char	*line;
	int		size_key;
	int		i;

	i = -1;
	size_key = ft_strlen(key);
	while (*(env + ++i))
	{
		line = *(env + i);
		if (ft_strcmp(line, key) == '=' && *(line + size_key) == '=')
			return (i);
	}
	return (-1);
}

unsigned char			ms_bt_unsetenv(char **cmd, char ***env)
{
	int		len;
	int		i;
	int		j;

	i = 0;
	len = ft_tablen((void**)cmd);
	if (len < 2)
		return (env_usage());
	if (!env || !*env)
		return (0);
	len = ft_tablen((void**)*env);
	while (*(cmd + ++i))
		if ((j = ms_env_index(*env, *(cmd + i))) != -1)
		{
			ft_memdel((void**)*env + j);
			ft_memmove((*env + j), (*env + j + 1), (len - j) * sizeof(char**));
		}
	return (0);
}