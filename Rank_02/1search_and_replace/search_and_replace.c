#include <unistd.h>

void	search_and_replace(char *str, char c1, char c2)
{
	while (*str)
	{
		if (*str == c1)
			*str = c2;
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 4 && !argv[2][1] && !argv[3][1])
		search_and_replace(argv[1], argv[2][0], argv[3][0]);
	write(1, "\n", 1);
}
