/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_bt_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:22:00 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/30 21:40:13 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned char	ms_bt_exit(char **cmd, char ***env)
{
	char	*param;
	(void)cmd;
	(void)env;

	param = *(cmd + 1);
	exit(param && ft_isint(param) ? ft_atoi(param) : 0);
}
