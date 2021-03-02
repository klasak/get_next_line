#include <unistd.h>
#include "get_next_line.h"

static int	read_result(int fd, char **str)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret;
	char	*temp;

	ret = 1;
	if (*str != NULL && gnl_strchr(*str, '\n') != NULL)
		return (ret);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret >= 0)
			buf[ret] = '\0';
		else
			return (-1);
		temp = gnl_join(*str, buf);
		if (!temp)
			return (-1);
		free(*str);
		*str = temp;
		if (gnl_strchr(*str, '\n') != NULL)
			return (ret);
	}
	return (ret);
}

static int	make_line(char **line, char **str)
{
	int		i;
	char	*rest;

	i = 0;
	rest = NULL;
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
	{
		(*str)[i] = '\0';
		rest = gnl_strdup(&(*str)[i + 1]);
	}
	*line = gnl_strdup(*str);
	if (!*line)
		return (-1);
	free(*str);
	*str = rest;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE < 1 || !BUFFER_SIZE || !line)
		return (-1);
	ret = read_result(fd, &str[fd]);
	if (ret < 0)
		return (-1);
	if (make_line(line, &str[fd]) < 0)
		return (-1);
	if (ret == 0 && str[fd] == NULL)
		return (0);
	return (1);
}
