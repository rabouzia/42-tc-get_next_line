/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:38:19 by rabouzia          #+#    #+#             */
/*   Updated: 2023/12/13 17:27:02 by rabouzia         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		if (s2[i] == '\n')
			break ;
		str[len1] = s2[i];
		len1++;
	}
	str[len1] = '\0';
	return (str);
}

char	*ft_substr(char *s)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(ft_strlen(s) + 1);
	i = 0;
	j = 0;
	while (s[i++])
	{
		if (s[i] == '\n')
		{
			i++;
			while (s[i])
			{
				str[j] = s[i];
				i++;
				j++;
			}
		}
	}
	str[j] = 0;
	free(s);
	return (str);
}

int	nl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strchr(char *str, char c)
{
	int	i;

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
	static char	*res;
	int			lu;
	char		buff[BUFFER_SIZE + 1];

	// char	*stockage;
	if (BUFFER_SIZE < 1 || fd > 1024 || fd < 0)
		return (NULL);
	//  d malloc(sizeof(char) * BUFFER_SIZE + 1);
	lu = 1;
	while (lu > 0 && (ft_strchr(buff, '\n') == 0))
	{
		// printf("buff: %s\n", buff);
		// printf("res: %s\n", res);
		// printf("stockage: %s\n", stockage);
		lu = read(fd, buff, BUFFER_SIZE);
		if (lu == -1)
			return (NULL);
		buff[lu] = '\0';
		// stockage = ft_substr(buff);
		res = ft_strjoin(res, buff);
	}
	// printf("res: %s\n", res);
	return (free(res), res);
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
// }