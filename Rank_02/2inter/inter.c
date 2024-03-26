#include <unistd.h>

void	inter(char *s1, char *s2)
{
	int	seen[256] = {0};

	while (*s2)
	{
		if (seen[(unsigned char)*s2] == 0)
			seen[(unsigned char)*s2] = 1;
		s2++;
	}
	while (*s1)
	{
		if (seen[(unsigned char)*s1] == 1)
		{
			write(1, s1, 1);
			seen[(unsigned char)*s1] = 2;
		}
		s1++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
}
