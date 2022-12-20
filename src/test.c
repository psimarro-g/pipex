#include "../inc/pipex.h"

char	**ft_q_split(char const *s, char c);

int	main(int argc, char **argv, char **envm)
{
	char **out;
	if (argc > 1 && envm)
	{
		out = ft_q_split(argv[1], ' ');
		while (*out)
    		ft_printf("%s\n", *out++);
	}
    return(0);
}
