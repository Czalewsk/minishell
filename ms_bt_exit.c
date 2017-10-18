/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_bt_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:22:00 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/18 09:47:24 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned char	ms_bt_exit(char **cmd, char ***env)
{
	char	*param;
	(void)cmd;
	(void)env;

	param = *(cmd + 1);
	if (ft_tablen((void**)cmd) > 2)
	{
		ft_putendl_fd("exit: too many arguments", 2);
		return (1);
	}
	ms_free_env(NULL);
	ms_free_cmd(NULL);
	exit(param ? ft_atoi(param) : 0);
}
