/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:19:25 by psimarro          #+#    #+#             */
/*   Updated: 2023/07/30 17:04:41 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error_cmd(char *cmd)
{
	char	*s;

	s = ft_strjoin("pipex: ", cmd);
	cmd = ft_strjoin(s, ": command not found\n");
	write(2, cmd, ft_strlen(cmd));
	free(s);
	free(cmd);
	exit(127);
}

void	error_file(void)
{
	write(1, "       0\n", 9);
	perror("pipex: input");
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
