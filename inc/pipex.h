/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:17:34 by psimarro          #+#    #+#             */
/*   Updated: 2022/12/18 21:42:17 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/inc/libft.h"
# include <fcntl.h>
# include <readline/readline.h>
# include <sys/wait.h>

typedef struct s_qsplit
{
	int	end;
	int	start;
}	t_qsplit;

char	*f_pathes(char *cmd, char **envm);
void	command(char *argv, char **envm);
int		open_file(char *argv, int i);
char	**ft_q_split(char const *s, char c);

//errors
void	arg_err(void);
void	error_cmd(void);
void	error_file(void);
void	error_premission(void);
void	error_pipe(void);
void	error_pid(void);
void	ft_perror(char *str);

#endif
