/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:22:57 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/01 18:34:17 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ms_prompt_get_host(void)
{
	char	hostname[1024];
	int		size;

	if (gethostname(hostname, 1024))
		return ;
	hostname[1023] = '\0';
	if (ft_strlen(hostname) > 15)
		return ;
	size = ft_strchr(hostname, '.') - hostname;
	size = size > 0 ? size + 1 : ft_strlen(hostname) + 1;
	hostname[size - 1] = ' ';
	write(1, hostname, size);
}

char		ms_print_git(fd)
{
	char	*line;
	char	*actual_head;
	int		ret;

	line = NULL;
	if ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((actual_head = ft_strrchr(line, '/')))
		{
			ft_putstr("git:["RED);
			ft_putstr(actual_head + 1);
			ft_putstr(C_DEFAULT"] ");
		}
		ft_strdel(&line);
	}
	close(fd);
	return (-1);
}

void		ms_prompt_git(void)
{
	int		fd;
	char	*path;
	char	*test_git;
	int		depth;

	path = NULL;
	if (!(path = getcwd(path, 0)))
		return ;
	depth = ft_howmany(path, '/');
	test_git = ft_strdup(".git/HEAD");
	while (--depth >= 0)
	{
		if ((fd = open(test_git, O_RDONLY)) > 0)
			depth = ms_print_git(fd);
		test_git = ft_strjoin_free("../", 0, test_git, 1);
	}
	ft_strdel(&test_git);
	ft_strdel(&path);
}

char		ms_print_prompt(void)
{
	ms_prompt_get_host();
	ms_prompt_git();
	ft_putstr(PROMPT);
	return (1);
}