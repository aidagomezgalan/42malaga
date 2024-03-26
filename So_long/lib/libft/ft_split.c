/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:37:53 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/27 14:57:09 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_count(char const *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		if (*s == c)
			flag = 0;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		i;
	int		start;
	char	**str;

	j = 0;
	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	str = malloc ((ft_str_count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (s[i] && j < ft_str_count(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start != i)
			str[j++] = ft_substr(s, start, i - start);
	}
	str[j] = 0;
	return (str);
}
