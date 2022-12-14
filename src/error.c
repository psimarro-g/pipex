/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:19:25 by psimarro          #+#    #+#             */
/*   Updated: 2022/12/14 18:03:12 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error_cmd(void)
{
	perror("command not found\n");
	exit(0);
}

void	error_file(void)
{
	perror("No such file or directory\n");
	exit(0);
}

void	error_premission(void)
{
	perror("Permission denied\n");
	exit(0);
}

void	error_pipe(void)
{
	perror("Pipe error\n");
	exit(0);
}

void	error_pid(void)
{
	perror("Pid error\n");
	exit(0);
}
