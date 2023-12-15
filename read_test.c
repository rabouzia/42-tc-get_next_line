#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
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
	while (s2[++i]) //&& s2[i - 1] != '\n')
	{
		str[len1] = s2[i];
		len1++;
		if (s2[i] == '\n')
			break ;
	}
	str[len1] = '\0';
	return (str);
}

int	main(void)
{
	char *s, *a;
	static char *d;
	d = "";
	s = "\n\n\n";
	a = "\n";
	//printf("1%s", for_strjoin(d, s));
	printf("%s", s);
	//printf("1%s", for_strjoin(d, a));
}