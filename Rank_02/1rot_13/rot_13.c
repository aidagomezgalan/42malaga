#include <unistd.h>

void	rot_13(char *str)
{
	while (*str)
	{
		if ((*str >= 'a' && *str <= 'm') || (*str >= 'A' && *str <= 'M'))
			*str += 13;
		else if ((*str > 'm' && *str <= 'z') || (*str > 'M' && *str <= 'Z'))
			*str -= 13;
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rot_13(argv[1]);
	write(1, "\n", 1);
}
