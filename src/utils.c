/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:20:34 by psimarro          #+#    #+#             */
/*   Updated: 2023/07/30 17:28:10 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <stdio.h>

char	**ft_q_split(char const *s, char c);

static char	**find_path(char **envm)
{
	char	**paths;
	int		i;

	i = 0;
	while (ft_strnstr(envm[i], "PATH", 4) == 0)
			i++;
	paths = ft_split(envm[i] + 5, ':');
	return (paths);
}

char	*f_pathes(char *cmd, char **envm)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	if (access(cmd, F_OK) == 0)
		return (cmd);
	paths = find_path(envm);
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
	ft_free_split(paths);
	return (0);
}

void	command(char *argv, char **envm)
{
	char	**cmd;
	char	*file_path;

	if (!*argv)
		ft_perror("pipex: Empty command", 0);
	cmd = ft_q_split(argv, ' ');
	if (!envm || !*envm)
	{
		envm[0] = "PATH=/usr/bin:";
		envm[1] = NULL;
	}
	file_path = f_pathes(cmd[0], envm);
	if (execve(file_path, cmd, envm) == -1)
		error_cmd(cmd[0]);
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
	if (file == -1 && i == 1)
		exit(127);
	else if (file == -1)
		error_file();
	return (file);
}

void	get_args(int argc, char **argv)
{
	if (argc < 5)
		arg_err();
	if (ft_strncmp(argv[1], "/dev/urandom", ft_strlen(argv[1])) == 0)
		ft_perror("Error", 0);
}
