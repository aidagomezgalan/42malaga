#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd;
	int		fd2;
	char	*str;
	char	*str2;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	str = get_next_line(fd);
	str2 = get_next_line(fd2);
	while (str)
	{
		printf("FD1: %s", str);
		printf("FD2: %s", str2);
		free(str);
		str = get_next_line(fd);
		str2 = get_next_line(fd2);
	}
	close(fd);
	close(fd2);
	// fd = 0;
	// str = get_next_line(fd);
	// printf("%s", str);
	return (0);
}
