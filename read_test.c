#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	return (str);
}

int	main(void)
{
	char *s;
	s = "en gs1250\nmon g\nar\ns";

	printf("%s", ft_substr(s));
}