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

void	ft_putnbr(int nbr)
{
	char	digit;

	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	digit = (nbr % 10) + '0';
	write(1, &digit, 1);
}

/*Optimización de la raíz cuadrada:
Si no hay factores menores o iguales a la raíz cuadrada de nbr,
podemos concluir que nbr es primo. (nbr = a * b)
*/
int	is_prime(int nbr)
{
	if (nbr < 2)
		return (0);

	if (nbr == 2)
		return (1);
	//Si es par no es primo
	if (nbr % 2 == 0)
		return (0);

	int	i = 3;

	while (i * i <= nbr)
	{
		if (nbr % i == 0)
			return (0);
		//Todos los números primos mayores que 2 son impares. (3 + 2; 5 + 2...)
		i += 2;
	}
	return (1);
}

int	add_prime_sum(int nbr)
{
	int	sum;
	int	i;

	sum = 0;
	i = 2;
	while (i <= nbr)
	{
		if (is_prime(i))
			sum += i;
		++i;
	}
	return (sum);
}

int	main(int argc, char **argv)
{
	int	nbr;

	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		ft_putnbr(add_prime_sum(nbr));
	}
	else
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
