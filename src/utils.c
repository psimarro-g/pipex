/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:20:34 by psimarro          #+#    #+#             */
/*   Updated: 2023/02/06 10:45:08 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <stdio.h>

char	**ft_q_split(char const *s, char c);

char	*f_pathes(char *cmd, char **envm)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envm[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envm[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i++], "/");
		path = ft_strjoin(part_path, cmd);
		if (access(path, F_OK) == 0)
		{
			free(part_path);
			ft_free_split(paths);
			return (path);
		}
		free(part_path);
		free(path);
	}
	return (0);
}

void	command(char *argv, char **envm)
{
	char	**cmd;
	char	*file_path;

	if (!*argv)
		ft_perror("Empty command", 0);
	cmd = ft_q_split(argv, ' ');
	if (!envm[0])
		ft_perror("Environment error", 1);
	file_path = f_pathes(cmd[0], envm);
	if (execve(file_path, cmd, envm) == -1)
		error_cmd();
	free(file_path);
	ft_free_split(cmd);
}

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		error_file();
	return (file);
}

void	arg_err(void)
{
	perror("Error: Bad argument\n");
	write(1, "input: ./pipex infile <cmd1> <cmd2> <...> outfile\n", 49);
	write(1, "./pipex here_doc <LIMITER> <cmd> <cmd1> <...> file\n", 51);
	exit(EXIT_SUCCESS);
}

void	ft_perror(char *str, int exit_code)
{
	perror(str);
	exit(exit_code);
}
