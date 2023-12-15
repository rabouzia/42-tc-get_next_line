/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:38:19 by rabouzia          #+#    #+#             */
/*   Updated: 2023/12/15 17:20:05 by rabouzia         ###   ########.fr       */
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
void	*ft_memchr(const char *str, int c)
{
	unsigned char	*res;
	int				i;

	i = 0;
	res = (unsigned char *)str;
	while (*res)
	{
		if (*res == (unsigned char)c)
			return (res);
		res++;
		i++;
	}
	return (NULL);
}
char	*ft_strdup(char *src)
{
	int		i;
	char	*r;
	int		d;

	if (!src)
		return (NULL);
	r = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!r)
		return (NULL);
	i = 0;
	d = 1;
	while (src[i] && d > 0)
	{
		if (src[i] == '\n')
			d--;
		r[i] = src[i];
		i++;
	}
	r[i] = 0;
	return (r);
}

char	*for_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	j = -1;
	if (!s1)
		return (ft_strdup(s2));
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j]) //&& s2[i - 1] != '\n')
	{
		str[i] = s2[j];
		i++;
		if (s2[j] == '\n')
			break ;
	}
	str[i] = '\0';
	return (free(s1), str);
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
char	*get_next_line(int fd)
{
	char		*res;
	int			lu;
	static char	buff[BUFFER_SIZE + 1] = {};

	if (BUFFER_SIZE < 1 || fd > 1024 || fd < 0)
		return (NULL);
	lu = 1;
	res = NULL;
	if (ft_memchr(buff, '\n') != 0)
	{
		if (ft_strlen(ft_memchr(buff, '\n') + 1) > 0)
			res = ft_strdup(ft_memchr(buff, '\n') + 1);
		rm_back(buff);
	}
	while (lu > 0 && (ft_strchr(res, '\n') == 0))
	{
		lu = read(fd, buff, BUFFER_SIZE);
		if (lu <= 0)
			break ;
		buff[lu] = '\0';
		res = for_strjoin(res, buff);
	}
	if (lu <= 0 && !res)
		return (NULL);
	return (res);
}

int	main(void)
{
	int		fd;
	char	*str;
	int		i;

	if ((fd = open("gnlTester/files/big_line_no_nl", O_RDONLY)) < 0)
	{
		printf("open failed");
		return (0);
	}
	i = 15;
	while (i--)
		printf("gnl:%s", get_next_line(fd));
}

// int	main(int ac, char **av)
// {
// 	int fd;
// 	char *line;

// 	(void)ac;
// 	if ((fd = open(av[1], O_RDONLY)) == -1)
// 		return (1);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }