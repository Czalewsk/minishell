/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_interpreter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:16:24 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/18 16:51:23 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ms_trim_tab(char ***tab)
{
	int		i;

	i = -1;
	while (tab && *(tab + ++i))
	{

	}
}

char		***ms_interpreter(char **line)
{
	char	**cmd;
	int		size;
	char	***ret;
	int		i;

	i = -1;
	cmd = ft_strsplit(*line, ';');
	size = ft_tablen((void**)cmd);
	ret = ft_memalloc(sizeof(char**) * (size + 1));
	while (++i < size)
		*(ret + i) = ft_strsplitwhitespaces(*(cmd + i));
	ft_strdel(line);
	i = -1;
	while (cmd && *(cmd + ++i))
		ft_memdel((void**)cmd + i);
	ft_memdel((void**)&cmd);
	return (ret);
}
