/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 16:56:04 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/01 16:07:15 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		ms_read_line(char **line)
{
	char	ret;

	if ((ret = get_next_line(0, line)) < 0)
		ft_putstr_fd("Error in Get_next_line : Can't read input\n", 2);
	if (ret <= 0)
	{
		ft_strdel(line);
		return (0);
	}
	return (1);
}
