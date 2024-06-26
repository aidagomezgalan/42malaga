#include <unistd.h>

int	ft_atoi(char *str)
{
	int	nbr;

	nbr = 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr);
}

void	print_hex(int nbr)
{
	char	*hex_digits;
	//char	hex_digits[] = "0123456789abcdef";

	hex_digits = "0123456789abcdef";
	if (nbr >= 16)
		print_hex(nbr / 16);
	write(1, &hex_digits[nbr % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
}
