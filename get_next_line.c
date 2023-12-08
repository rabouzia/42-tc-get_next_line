/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:14:43 by rabouzia          #+#    #+#             */
/*   Updated: 2023/12/08 15:48:55 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	not_a_nl(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char *buff;
	static char *stock;
	int reader;
	char *tmp;

	if (BUFFER_SIZE < 1 || fd > 1024 || fd < 0)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	reader = 1;
	while (not_a_nl(stock, '\n') == 1 && reader > 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
			return (NULL);
		tmp = stock;
		stock = ft_strjoin(tmp, buff);
	}
}