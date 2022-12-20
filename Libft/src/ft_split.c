/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:53:03 by psimarro          #+#    #+#             */
/*   Updated: 2022/12/18 21:46:15 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*aux;
	int		j;
	int		start;

	if (!s)
		return (0);
	aux = ft_trimf(s, (char []){c, '\0'});
	j = ft_nsep(aux, c);
	ret = ft_calloc(sizeof(char *), j + 2);
	if (!ret)
		return (0);
	j = 0;
	while (aux[j])
	{
		start = j;
		while (aux[j] != c && aux[j])
			j++;
		*ret++ = ft_substr(aux, start, j - start);
		if (aux[j])
			j++;
	}
	free(aux);
	return (ret);
}
