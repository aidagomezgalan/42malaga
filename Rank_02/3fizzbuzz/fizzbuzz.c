#include <unistd.h>

void	ft_putnbr(int n)
{
	char	digit;

	if (n >= 10)
		ft_putnbr(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int	main(void)
{
	int	i = 1;

	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
}

// void	fizzbuzz(void)
// {
// 	int	i;
// 	int	nbr;
// 	int	rest;

// 	i = 1;
// 	nbr = 0;
// 	rest = 0;
// 	while (i <= 100)
// 	{
// 		if (i % 3 == 0 && i % 5 == 0)
// 			write(1, "fizzbuzz", 8);
// 		else if (i % 3 == 0)
// 			write(1, "fizz", 4);
// 		else if (i % 5 == 0)
// 			write(1, "buzz", 4);
// 		else if (i > 10)
// 		{
// 			nbr = i / 10 + '0';
// 			write(1, &nbr, 1);
// 			rest = i % 10 + '0';
// 			write(1, &rest, 1);
// 		}
// 		else
// 		{
// 			nbr = i + '0';
// 			write(1, &nbr, 1);
// 		}
// 		i++;
// 		write(1, "\n", 1);
// 	}
// }
