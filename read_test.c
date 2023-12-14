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

char	*after_strjoin(char *s1, char *s2)
{
	int			i;
	int			len1;
	static char	*str;

	len1 = ft_strlen(s1);
	if (!s1)
		return NULL;
	str = (char *)malloc(sizeof(char) * (len1 + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\n')
		i++;
	i = -1;
	while (s2[++i])
	{
		str[len1] = s2[i];
		len1++;
	}
	str[len1] = '\0';
	return (str);
}

int	main(void)
{
	char *s, *a;
	char *d;
	d = "";
	s = " en gs1250\nmon g\nar\ns";
	a = "je suis";
	printf("%s", after_strjoin(s, d));
}