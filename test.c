#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envm)
{
	char **out;
	int		i;
	char	*s;
	char	str[20] = "hey:wassup:man:wyd\0";

	i = 0;
	s = &str[0];
	while (ft_strnstr(envm[i], "PATH", 4) == 0)
		i++;
	ft_printf("%s\n", s);
	if (argc > 1 && argv)
	{
		out = ft_split(s, ':');
		while (*out)
    		ft_printf("%s\n", *out++);
	}
    return(0);
}
