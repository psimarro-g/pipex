#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <readline/readline.h>

typedef struct s_datas
{
	char	**envp;
	char	**av;

	int		ac;
	int		outfile_fd;
	int		infile_fd;
	int		p_fd[2];

	t_bool	is_heredoc;
}	t_datas;

/* utils.c */
void	error(const char *error);
t_datas	init_datas(int ac, char **av, char **envp);

/* parse_env_cmd.c */
char	**get_env_paths(char **envp);
char	*get_binary(char *cmd, char **env_parsed);

/* execution.c */
void	execute_commands(t_datas *datas);

/* heredoc.c */
void	heredoc(t_datas *datas, char *limiter);

#endif