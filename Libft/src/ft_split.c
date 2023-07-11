/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:53:03 by psimarro          #+#    #+#             */
/*   Updated: 2023/07/11 20:02:54 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	**set_ret(char	*aux, char c)
{
	char	**ret;
	int		j;

	j = ft_nsep(aux, c);
	ret = ft_calloc(sizeof(char *), j + 2);
	if (!ret)
		return (0);
	return (ret);
}

static char	**ft_split_aux(char **ret, char *aux, char c)
{
	int		j;
	int		i;
	int		start;

	j = 0;
	i = 0;
	while (aux[j])
	{
		start = j;
		while (aux[j] != c && aux[j])
			j++;
		ret[i++] = ft_substr(aux, start, j - start);
		if (ret[i - 1] == NULL)
		{
			free(aux);
			ft_free_split(ret);
			return (NULL);
		}
		while (aux[j] && aux[j] == c)
			j++;
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*aux;

	if (!s)
		return (0);
	aux = ft_trimf(s, (char []){c, '\0'});
	if (!aux)
		return (NULL);
	ret = set_ret(aux, c);
	if (!ret)
		return (NULL);
	ret = ft_split_aux(ret, aux, c);
	if (!ret)
		return (NULL);
	free(aux);
	return (ret);
}
