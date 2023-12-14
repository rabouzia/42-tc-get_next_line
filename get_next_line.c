/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:38:19 by rabouzia          #+#    #+#             */
/*   Updated: 2023/12/14 14:50:18 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*r;

	r = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!r)
		return (NULL);
	i = 0;
	while (src[i])
	{
		r[i] = src[i];
		i++;
	}
	r[i] = 0;
	return (r);
}

char	*for_strjoin(char *s1, char *s2)
{
	int		i;
	int		len1;
	char	*str;

	len1 = ft_strlen(s1);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len1 + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		str[len1] = s2[i];
		len1++;
		if (s2[i] == '\n')
			break ;
	}
	str[len1] = '\0';
	return (free(s1), str);
}

int is_a_nl(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return(0);
		i++;
	}
	return 1;
}

int	ft_strchr(char *str, char c)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (i < ft_strlen(str) + 1)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*res;
	int			lu;
	static char	buff[BUFFER_SIZE + 1] = {};

	if (BUFFER_SIZE < 1 || fd > 1024 || fd < 0)
		return (NULL);
	lu = 1;
	res = NULL;
	if (buff[0]== '\n')
		return (NULL);
	while (lu > 0 && (ft_strchr(res, '\n') == 0))
	{
		lu = read(fd, buff, BUFFER_SIZE);
		if (lu == -1)
			return (NULL);
		buff[lu] = '\0';
		res = for_strjoin(res, buff);
	}
	buff[0] = '\0';
	return (res);
}

// int	main(void)
// {
// 	int fd;
// 	if ((fd = open("xaxa", O_RDONLY)) < 0)
// 	{
// 		printf("open failed");
// 		return (0);
// 	}
// 	int i = 5;
// 	printf("gnl: %s\n", get_next_line(fd));
// 	printf("gnl: %s\n", get_next_line(fd));
// 	printf("gnl: %s\n", get_next_line(fd));
// 	printf("gnl: %s\n", get_next_line(fd));
// 	printf("gnl: %s\n", get_next_line(fd));
// 	printf("gnl: %s\n", get_next_line(fd));
// }