/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 17:05:49 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/27 15:23:13 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static volatile char	g_err;

int		main(int ac, char **av, char **env)
{
	char	*line;
	pid_t	father;
	char	**cmd;
	int		i;

	(void)ac;
	(void)av;
	i = 0;
	while (env[i])
		ft_printf("%s\n", env[i++]);
	while (ft_printf("$>") && get_next_line(0, &line) > 0)
	{
		g_err = 0;
		cmd = ft_strsplit(line, ' ');
		father = fork();
		if (!father)
		{
			execve(*cmd, (cmd), env);
			g_err = ft_printf("Fail to launch the command\n");
		}
		else if (father > 0)
		{
			wait(NULL);
		}
		!g_err ? ft_printf("Commande fini\n") : 0;
	}
}
