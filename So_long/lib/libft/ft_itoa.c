/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:06:49 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/26 14:12:07 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*str;
	long		nbr;
	int			length;

	length = ft_len_nbr(n);
	nbr = n;
	str = malloc (sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	str[length--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[length--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
