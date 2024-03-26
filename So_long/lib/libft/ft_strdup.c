/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:41:38 by aidgomez          #+#    #+#             */
/*   Updated: 2022/11/09 01:41:38 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!s2)
		return (NULL);
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}
