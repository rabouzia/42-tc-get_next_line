/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:38:19 by rabouzia          #+#    #+#             */
/*   Updated: 2023/12/12 17:01:43 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\n' && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*stockage;
	char		*res;
	int			lu;
	char		buff[BUFFER_SIZE];

    res = malloc(BUFFER_SIZE * 2 + 1);
	lu = 0;
	while ()
	{
		lu = read(fd, buff, BUFFER_SIZE);
		if (lu == -1)
			return (NULL);
		buff[lu] = '\0';
		res = ft_strcat(res, buff);
        stockage = ft_substr(buff, '\n')
	}
	return (res);
}

int	main(void)
{
	int fd;
	if ((fd = open("xaxa", O_RDONLY)) < 0)
	{
		printf("open failed");
		return (0);
	}
	printf("fd = %d\n", fd);
	printf("%s", get_next_line(fd));
}