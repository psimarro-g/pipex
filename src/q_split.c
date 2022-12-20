/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:17:59 by psimarro          #+#    #+#             */
/*   Updated: 2022/12/18 18:27:19 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	  ft_narg(char const *str, char c)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (*str)
		if (*str++ == c)
			i++;
	return (i);
}

char	*get_quotes(char const *str, t_qsplit *t, char c)
{
	int end;

	end = t->end;
	if (str[end++] == '\'')
	{
		while (str[end] && str[end] != '\'')
			end++;
	}
	else if (str[end++] == '\"')
	{
		while (str[end] && str[end] != '\"')
			end++;
	}
	if (!str[end])
	{
		while (str[t->end] && str[t->end] != c)
			t->end++;
	}
	else
	{
		t->start = t->end + 1;
		t->end = end;
	}
	return (NULL);
}

char	**ft_q_split(char const *s, char c)
{
	char		**ret;
	int			i;
	t_qsplit	*t;

	if (!s)
		return (0);
	i = 0;
	t = (t_qsplit *)ft_calloc(1, sizeof(t_qsplit));
	ret = ft_calloc(sizeof(char *), ft_narg(s, c) + 2);
	if (!ret)
		return (0);
	t->end = 0;
	while (s[t->end])
	{
		t->start = t->end;
		while (s[t->end] && s[t->end] != c && s[t->end] != '\'' && s[t->end] != '\"')
			t->end++;
        if ((s[t->end] == '\'' || s[t->end] == '\"'))
			get_quotes(s, t, c);
        ret[i++] = ft_substr(s, t->start, t->end - t->start);
		if (s[t->end])
			t->end++;
		if (s[t->end] == c)
			t->end++;
	}
	return (ret);
}
