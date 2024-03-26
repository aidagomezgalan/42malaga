#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		while (*argv[1] == ' ' || *argv[1] == '\t')
			argv[1]++;
		while (*argv[1] && *argv[1] != ' ' && *argv[1] != '\t')
		{
			write(1, argv[1], 1);
			argv[1]++;
		}
	}
	write(1, "\n", 1);
}
// int is_space(char c)
// {
// 	return (c == ' ' || c == '\t');
// }
// void first_word(char *str)
// {
// 	while (is_space(*str))
// 		str++;
// 	while (*str && !is_space(*str))
// 	{
// 		write(1, str, 1);
// 		str++;
// 	}
// }
// int main(int argc, char **argv)

// {
// 	if (argc == 2)
// 		first_word(argv[1]);
// 	write(1, "\n", 1);
// 	return (0);
// }
