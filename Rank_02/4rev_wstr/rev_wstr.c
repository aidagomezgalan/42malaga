#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	rev_wstr(char *str)
{
	int	i;
	int	start_word;

	i = 0;
	start_word = 0;
	while (str[i])
		i++;
	while (i > 0)
	{
		if (is_space(str[i]))
		{
			start_word = i + 1;
			while (!is_space(str[start_word]) && str[start_word])
			{
				write(1, &str[start_word], 1);
				start_word++;
			}
			write(1, " ", 1);
		}
		i--;
	}
	while (!is_space(str[i]) && str[i])
		write(1, &str[i++], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
