#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	rostring(char *str)
{
	int	i;
	int	is_first_word;
	int	start_word;

	i = 0;
	is_first_word = 1;
	start_word = 0;
	while (str[i])
	{
		while (!is_space(str[i]) && str[i])
		{
			if (is_first_word == 1)
			{
				start_word = i;
				while (!is_space(str[i]) && str[i])
					i++;
				is_first_word = 0;
			}
			else
			{
				while (!is_space(str[i]) && str[i])
					write(1, &str[i++], 1);
				write(1, " ", 1);
			}
		}
		while (is_space(str[i]))
			i++;
	}
	while (!is_space(str[start_word]) && str[start_word])
		write(1, &str[start_word++], 1);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}
