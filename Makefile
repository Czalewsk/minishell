# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/19 08:42:40 by czalewsk          #+#    #+#              #
#    Updated: 2017/10/17 17:52:39 by czalewsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./minishell
FLAGS = -Wall -Werror -Wextra -g
OBJS = $(SRCS:.c=.o)
SRCS = minishell.c ms_bin.c ms_bt_exit.c ms_builtin.c ms_env_init.c \
	   ms_env_value.c ms_execute.c ms_interpreter.c ms_prompt.c ms_read_line.c \
	   ms_signal_hdlr.c ms_bt_echo.c ms_bt_cd.c

INCLUDES = -I ./libft

DEP = Makefile minishell.h ./libft/libft.a

LIBNAME = -lft
LIBPATH = ./libft
LIB = -L $(LIBPATH)

all: mylibft $(NAME)

$(NAME): $(OBJS)
	gcc $(LIB) $(LIBNAME) $(FLAGS) $(OBJS) -o $(NAME)

mylibft:
	make -C $(LIBPATH)

%.o: %.c $(DEP)
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBPATH) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.NOTPARELLEL: all clean fclean re
