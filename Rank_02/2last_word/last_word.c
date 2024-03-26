#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	last_word(char *str)
{
	int	i;
	int	end_word;

	i = 0;
	end_word = 0;
	while (str[i])
	{
		if (!is_space(str[i]))
			end_word = i;
		i++;
	}
	while (!is_space(str[end_word]))
		end_word--;
	end_word += 1;
	while (str[end_word] && !is_space(str[end_word]))
	{
		write(1, &str[end_word], 1);
		end_word++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
}
