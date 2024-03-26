/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:34:46 by aidgomez          #+#    #+#             */
/*   Updated: 2022/11/09 00:34:46 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	while (i < n * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
