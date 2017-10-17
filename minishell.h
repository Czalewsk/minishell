/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 17:01:17 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/17 17:52:06 by czalewsk         ###   ########.fr       */
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
# include <time.h>

# define PROMPT "$> "

extern volatile char	g_prpt_display;

typedef struct		s_ms_builtin
{
	char	name[20];
	void	*f;
}					t_ms_builtin;

typedef struct		s_ms_process
{
	pid_t			pid;
	int				ret;
}					t_ms_process;

void			ms_init_sgnl_hdlr(void);
void			ms_env_init(char ***env);
char			ms_print_prompt(unsigned char ret);
char			ms_read_line(char **line);
char			***ms_interpreter(char **line);
unsigned char	ms_execute(char ***cmd, char ***env, t_ms_process *info);
void			ms_print_exit_status(unsigned char ret);
void			*ms_check_is_builtin(char *cmd);
char			*ms_check_bin(char *exec, char **env);
unsigned char	ms_exec_bin(char *path, char **exec, char ***env,
		t_ms_process *info);
char			*ms_env_value(char *name, int size_name, char **env);
void			ms_free_env(char ***env);
void			ms_free_cmd(char ****cmd);

unsigned char	ms_bt_exit(char **cmd, char ***env);
unsigned char	ms_bt_echo(char **cmd, char ***env);
unsigned char	ms_bt_cd(char **cmd, char ***env);

#endif