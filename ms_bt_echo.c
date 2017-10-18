/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_bt_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:13:25 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/18 10:32:01 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned char	ms_bt_echo(char **cmd, char ***env)
{
	int		i;
	char	nl;
	int		len;

	(void)env;
	len = 0;
	nl = 1;
	i = 1;
	len = ft_tablen((void**)cmd);
	if (len > 2 && !ft_strcmp(*(cmd + 1), "-n"))
	{
		i++;
		nl = 0;
	}
	while (i < len)
	{
		ft_putstr(*(cmd + i++));
		i < len ? write(1, " ", 1) : 0;
	}
	nl ? write(1, "\n", 1) : 0;
	return (0);
}
