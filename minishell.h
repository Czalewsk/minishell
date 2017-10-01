/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 17:01:17 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/01 19:09:09 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_H
# define __MINISHELL_H

# include "./libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/signal.h>
# include <sys/wait.h>
# include <limits.h>
# include <signal.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <termios.h>

# define PROMPT "$>"

extern volatile char	g_prpt_display;

typedef struct		s_ms_builtin
{
	char	name[20];
	void	*f;
}					t_ms_builtin;

void			ms_init_sgnl_hdlr(void);
void			ms_env_init(char ***env);
char			ms_print_prompt(void);
char			ms_read_line(char **line);
char			***ms_interpreter(char **line);
void			ms_execute(char ***cmd, char ***env);
void			ms_print_exit_status(unsigned char ret);
void			*ms_check_is_builtin(char *cmd);
char			*ms_check_bin(char *exec, char **env);
unsigned char	ms_exec_bin(char *path, char **exec, char ***env);
char			*ms_env_value(char *name, int size_name, char **env);
void			ms_free_env(char ***env);

unsigned char	ms_bt_exit(char **cmd, char ***env);

#endif