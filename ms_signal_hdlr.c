/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal_hdlr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 09:37:50 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/30 16:13:09 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ms_signal_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	g_prpt_display ? ms_print_prompt(NULL) : 0;
	if (signal(SIGINT, ms_signal_sigint) == SIG_ERR)
		ft_putendl_fd("Error in signal fucntion\n", 2);
}

void		ms_signal_hdlr(void)
{
	if (signal(SIGINT, ms_signal_sigint) == SIG_ERR)
		ft_putendl_fd("Error in signal fucntion\n", 2);
}