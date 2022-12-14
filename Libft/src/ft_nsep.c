/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:51:21 by psimarro          #+#    #+#             */
/*   Updated: 2022/12/18 21:44:42 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nsep(char *str, char c)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (*str)
	{
		if (*str++ == c)
		{
			while (*str == c)
				str++;
			i++;
		}
	}
	return (i);
}
