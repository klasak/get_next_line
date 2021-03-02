#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>

int		get_next_line(int fd, char **line);
size_t	gnl_strlen(const char *s);
char	*gnl_strdup(const char *s);
char	*gnl_join(const char *s1, const char *s2);
char	*gnl_strchr(const char *s, int c);

#endif
