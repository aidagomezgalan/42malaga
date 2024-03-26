#include <stdlib.h>

int	nbr_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*str;

	len = nbr_len(nbr);
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	else if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		--len;
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
