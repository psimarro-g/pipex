/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:04:13 by psimarro          #+#    #+#             */
/*   Updated: 2023/07/30 17:04:54 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	arg_err(void)
{
	perror("Error: Bad argument\n");
	write(1, "input: ./pipex infile <cmd1> <cmd2> <...> outfile\n", 49);
	write(1, "./pipex here_doc <LIMITER> <cmd> <cmd1> <...> file\n", 51);
	exit(127);
}

void	ft_perror(char *str, int exit_code)
{
	perror(str);
	exit(exit_code);
}
