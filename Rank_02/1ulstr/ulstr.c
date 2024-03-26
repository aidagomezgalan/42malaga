#include <unistd.h>

void	ulstr(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str >= 'z')
			*str -= 32;
		else if (*str >= 'A' && *str >= 'Z')
			*str += 32;
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ulstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
