/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 17:05:49 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/28 19:29:23 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static volatile char	g_is_display;

void	ms_signal_handler(int sig)
{
	(void)sig;
//	ft_printf("\nsig(%i)=%b\n", sig, sig);
	write(1, "\n", 1);
	g_is_display ? ft_putstr("$>") : 0;
	if (signal(SIGINT, ms_signal_handler) == SIG_ERR)
		ft_printf("Error in signal fucntion\n");
}

int		main(int ac, char **av, char **env)
{
	char				*line;
	pid_t				father;
	char				**cmd;
	int					i;
	int					ret;

	i = 0;
	if (signal(SIGINT, ms_signal_handler) == SIG_ERR)
		ft_printf("Error in signal fucntion\n");
	while (env[i])
		ft_printf("%s\n", env[i++]);
	while (!ac || av)
	{
		ret = 0;
		g_is_display = 1;
		ft_putstr("$>");
		if (get_next_line(0, &line) < 0)
			break ;
		g_is_display = 0;
		cmd = ft_strsplit(line, ' ');
		father = fork();
		if (!father)
		{
			execve(*cmd, (cmd), env);
			exit(-1);
		}
		else if (father > 0)
			wait(&ret);
		WIFEXITED(ret) && WEXITSTATUS(ret) != UCHAR_MAX ?
			ft_printf("Successful command\n") : ft_printf("Fail command\n");
	}
	return (0);
}
