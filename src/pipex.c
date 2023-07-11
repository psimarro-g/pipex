/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:17:18 by psimarro          #+#    #+#             */
/*   Updated: 2023/07/11 18:31:02 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	parent_process_hd(int fd[2])
{
	close(fd[1]);
	dup2(fd[0], 0);
	wait(NULL);
}

static void	child_process(char *argv, char **envm)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error_pipe();
	pid = fork();
	if (pid == -1)
		error_pid();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		command(argv, envm);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
}

static void	here_doc(char *limiter, int argc)
{
	pid_t	id;
	int		fd[2];
	char	*line;

	if (argc < 6)
		arg_err();
	if (pipe(fd) == -1)
		error_pipe();
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		while (1)
		{
			line = get_next_line(0);
			if (!line)
				ft_perror("Error: get next line failed\n", 0);
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
		parent_process_hd(fd);
}

static void	get_args(int argc, char **argv)
{
	if (argc < 5)
		arg_err();
	if (ft_strncmp(argv[1], "/dev/urandom", ft_strlen(argv[1])) == 0)
		arg_err();
}

int	main(int argc, char **argv, char **envm)
{
	int	i;
	int	files[2];

	get_args(argc, argv);
	i = 1;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		files[1] = open_file(argv[argc - 1], 0);
		here_doc(argv[2], argc);
	}
	else
	{
		i = 2;
		files[1] = open_file(argv[argc - 1], 1);
		files[0] = open_file(argv[1], 2);
		dup2(files[0], 0);
	}
	while (i < argc - 2)
		child_process(argv[i++], envm);
	dup2(files[1], 1);
	command(argv[argc - 2], envm);
	close(files[1]);
	if (!(ft_strncmp(argv[1], "here_doc", 8) == 0))
		close(files[0]);
	return (0);
}
