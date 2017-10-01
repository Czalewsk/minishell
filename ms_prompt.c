/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:22:57 by czalewsk          #+#    #+#             */
/*   Updated: 2017/10/01 15:28:11 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		ms_print_prompt(char ***env)
{
	(void)env;
	ft_putstr(PROMPT);
	return (1);
}