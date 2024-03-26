/*Por ejemplo, para determinar si 16 es una potencia de 2,
dividimos 16 por 2 repetidamente:
16÷2=8, 8÷2=4, 4÷2=2, 2÷2=1
Como llegamos a 1, 16 es una potencia de 2.*/

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n > 1)
	{
		// Si el resto no es 0, no es una potencia de 2
		if (n % 2 != 0)
			return (0);
		n = n / 2;
	}
	return (1);
}

// int	is_power_of_2(unsigned int n)
// {
// 	if (n == 2 || n == 1)
// 		return (1);
// 	if (n == 0)
// 		return (0);
// 	// while (n % 2 == 1)
// 	// 	return (0);
// 	while (n > 2)
// 	{
// 		if (n % 2 == 1)
// 			return (0);
// 		n = n / 2;
// 	}
// 	return (1);
// }
