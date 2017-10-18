/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_bt_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:45:17 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/18 10:32:22 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned char	ms_bt_cd(char **cmd, char ***env)
{
	int				len;
	unsigned char	ret;

	(void)env;
	len = ft_tablen((void**)cmd);
	if (len > 2)
	{
		ft_putstr_fd("cd: string not in pwd: ", 2);
		ft_putendl_fd(*(cmd + 1), 2);
		return (1);
	}
	if ((ret = (len == 1) ? chdir("/") : chdir(*(cmd + 1))))
	{
		if (access(*(cmd + 1), X_OK))
			ft_putstr_fd("cd: permission denied: ", 2);
		else
			ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(*(cmd + 1), 2);
	}
	return (ret);
}
