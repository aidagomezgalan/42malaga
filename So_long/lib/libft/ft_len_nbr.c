/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:08:41 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/26 14:09:03 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_nbr(long n)
{
	int	length;

	length = 0;
	if (n == 0)
		length = 1;
	else if (n < 0)
	{
		n *= -1;
		length++;
	}
	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}
