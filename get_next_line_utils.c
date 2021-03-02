#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}

char	*gnl_strdup(const char *s)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	p = (char*)malloc(sizeof(char) * (gnl_strlen(s) + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*str_concatanate(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*p;

	p = (char*)malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!p)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}

char	*gnl_join(const char *s1, const char *s2)
{
	char	*p;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (gnl_strdup(s2));
	p = str_concatanate(s1, s2);
	if (!p)
		return (0);
	return (p);
}

char	*gnl_strchr(const char *s, int c)
{
	if (c == '\0')
	{
		while (*s != '\0')
		{
			s++;
		}
		return ((char *)s);
	}
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}
