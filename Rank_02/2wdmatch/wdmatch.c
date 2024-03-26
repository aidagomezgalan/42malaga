#include <unistd.h>

void	wdmatch(char *s1, char *s2)
{
	int seen[256] = {0};

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
			seen[(unsigned char)*s1] = 0;
			write(1, s1, 1);
		}
		s1++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		wdmatch(argv[1], argv[2]);
	write(1, "\n", 1);
}
// static char	*wdmatch(char *s1, char *s2)
// {
// 	while (*s1 && *s2)
// 	{
// 		if (*s1 == *s2)
// 			s1++;
// 		s2++;
// 	}
// 	if (*s1 == '\0')
// 		return (s1);
// 	return (NULL);
// }

// int	main(int argc, char **argv)
// {
// 	char	*tmp;

// 	if (argc == 3)
// 	{
// 		tmp = wdmatch(argv[1], argv[2]);
// 		if (tmp != NULL)
// 			write(1, argv[1], tmp - argv[1]);
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }
