#include "minishell.h"

int main(int ac, char **av, char **env)
{
	char			*line;
	char			***cmd;
	char			**exec;
	unsigned char	(*f)(char **, char ***);
	int				i;

	(void)ac;
	(void)av;
	while (ms_read_line(&line))
	{
		i = -1;
		if ((cmd = ms_interpreter(&line)))
		{
			while ((exec = *(cmd + ++i)))
			{
				if ((f = ms_check_is_builtin(*exec)))
					f(exec, NULL);
				else
					ms_check_bin(*exec, env);
			}
		}
	}
}
