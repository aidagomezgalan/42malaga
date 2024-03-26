/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:14:45 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/16 18:35:11 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (s1)
	{
		while (s1[i])
			str[j++] = s1[i++];
		free(s1);
	}
	i = 0;
	if (!s2)
		return (str);
	while (s2[i])
		str[j++] = s2[i++];
	return (str);
}
