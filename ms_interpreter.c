/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_interpreter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:16:24 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/01 19:05:17 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	while(++i < size)
		*(ret + i) = ft_strsplit(*(cmd + i), ' ');
	ft_strdel(line);
	i = -1;
	while (cmd && *(cmd + ++i))
		ft_memdel((void**)cmd + i);
	ft_memdel((void**)&cmd);
	return (ret);
}
