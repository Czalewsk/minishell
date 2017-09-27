/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 17:05:49 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/24 17:19:59 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	pid_t	father;

	if (ac <= 1)
		ft_printf("Pas de paramatres...\n");
	else
	{
		father = fork();
		if (father > 0)
		{
			execve(av[1], av + 1, env);
		}
		else if (!father)
		{
			wait(NULL);
		}
	}
}
