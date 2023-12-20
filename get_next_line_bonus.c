/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:38:19 by rabouzia          #+#    #+#             */
/*   Updated: 2023/12/19 16:40:12 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	rm_back(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	i++;
	j = 0;
	while (str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = '\0';
}

char	*gnl(char **buff, int fd)
{
	char	*res;
	int		lu;

	lu = 1;
	res = NULL;
	if (ft_memchr(buff[fd], '\n') != 0)
	{
		if (ft_strlen(ft_memchr(buff[fd], '\n') + 1) > 0)
			res = ft_strdup(ft_memchr(buff[fd], '\n') + 1);
		rm_back(buff[fd]);
	}
	while (lu > 0 && (ft_strchr(res, '\n') == 0))
	{
		lu = read(fd, buff[fd], BUFFER_SIZE);
		if (lu <= 0)
			break ;
		buff[fd][lu] = '\0';
		res = for_strjoin(res, buff[fd]);
	}
	if (lu <= 0 && !res)
		return (NULL);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buff[FD_MAX] = {0};
	char		*check;

	if (BUFFER_SIZE < 1 || fd > FD_MAX - 1 || fd < 0)
		return (NULL);
	if (buff[fd] == NULL)
	{
		buff[fd] = malloc(BUFFER_SIZE + 1);
		buff[fd][0] = '\0';
	}
	if (!buff[fd])
		return (NULL);
	check = gnl(buff, fd);
	if (!check)
	{
		free(buff[fd]);
		buff[fd] = NULL;
	}
	return (check);
}
