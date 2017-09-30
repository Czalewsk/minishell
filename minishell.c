/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:36:14 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/30 20:13:13 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile char	g_prpt_display = 0;

int			print_usage(char *name)
{
	ft_putstr(name);
	ft_putendl(": No parameters needed");
	return (1);
}

int				main(int ac, char **av, char **env)
{
	char			*line;
	char			***cmd;

	if (ac > 1)
		return(print_usage(*av));
	ms_init_sgnl_hdlr();
	ms_env_init(&env);
	while (av)
	{
		g_prpt_display = ms_print_prompt(&env);
		if (!ms_read_line(&line))
			break ;
		g_prpt_display = 0;
		if ((cmd = ms_interpreter(&line)))
				ms_execute(cmd, env);
	}
}