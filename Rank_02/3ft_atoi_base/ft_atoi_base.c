#include <stdio.h>

// Base 16 = "0123456789abcdef" o "0123456789ABCDEF"
// Base 4 = "0123"
// Base 2 (binario) = "01"
// Convertir un número, de una base dada, a base 10:
// resultado = resultado x base + dígito
// Ej: "1a" en base 16:
// 0 x 16 + 1 = 1
// 1 x 16 + 10 = 26

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_char_to_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	// Carácter no válido
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	sign;
	int	digit;

	result = 0;
	sign = 1;
	if (str_base < 2 || str_base > 16)
		return (0);
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		digit = ft_char_to_digit(*str);
		if (digit < 0 || digit >= str_base)
			return (0);
		result = result * str_base + digit;
		str++;
	}
	return (result * sign);
}
