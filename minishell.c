/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:36:14 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/17 12:46:20 by czalewsk         ###   ########.fr       */
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

void			ms_free_cmd(char ****cmd)
{
	static	char****cmd_cache;
	char	***tmp;
	int		i;
	int		j;

	if (!cmd_cache)
		cmd_cache = cmd;
	cmd = cmd_cache;
	if (!(tmp = *cmd))
		return ;
	i = -1;
	while (*(tmp + ++i))
	{
		j = -1;
		while (*(*(tmp + i) + ++j))
			ft_strdel((*(tmp + i) + j));
		ft_memdel((void**)tmp + i);
	}
	ft_memdel((void**)cmd);
}

int				main(int ac, char **av, char **env)
{
	char			*line;
	char			***cmd;
	unsigned char	ret;
	t_ms_process	info;

	if (!(ret = 0) && ac > 1)
		return(print_usage(*av));
	ms_init_sgnl_hdlr();
	ms_env_init(&env);
	while (av)
	{
		g_prpt_display = ms_print_prompt(ret);
		if (!ms_read_line(&line))
			break ;
		g_prpt_display = 0;
		if ((cmd = ms_interpreter(&line)))
		{
			ret = ms_execute(cmd, &env, &info);
			ms_free_cmd(&cmd);
		}
		else
			ret = -1;
	}
	ms_free_env(NULL);
	return (0);
}