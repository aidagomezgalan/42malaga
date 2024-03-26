/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:48:49 by aidgomez          #+#    #+#             */
/*   Updated: 2023/03/10 14:48:49 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr(int nb)
{
	char	*str;
	int		count;

	str = ft_itoa(nb);
	count = ft_printstr(str);
	free (str);
	return (count);
}

int	ft_putnbru(unsigned int nb)
{
	char	*str;
	int		count;

	str = ft_itoau(nb);
	count = ft_printstr(str);
	free (str);
	return (count);
}
