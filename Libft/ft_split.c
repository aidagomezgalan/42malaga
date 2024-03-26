/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aida <aida@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:37:53 by aidgomez          #+#    #+#             */
/*   Updated: 2023/10/12 12:41:40 by aida             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_count(char const *s, char c)
{
	int	number_words;
	int	separator;

	number_words = 0;
	separator = 0;
	while (*s)
	{
		if (*s != c && separator == 0)
		{
			number_words++;
			separator = 1;
		}
		if (*s == c)
			separator = 0;
		s++;
	}
	return (number_words);
}

char	**ft_split(char const *s, char c)
{
	int		substr_count;
	int		char_index;
	int		substr_start;
	char	**str;

	substr_count = 0;
	char_index = 0;
	substr_start = 0;
	if (!s)
		return (NULL);
	str = malloc ((ft_str_count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (s[char_index] && substr_count < ft_str_count(s, c))
	{
		while (s[char_index] && s[char_index] == c)
			char_index++;
		substr_start = char_index;
		while (s[char_index] && s[char_index] != c)
			char_index++;
		if (substr_start != char_index)
			str[substr_count++] = ft_substr(s, substr_start, char_index - substr_start);
	}
	str[substr_count] = 0;
	return (str);
}
