#include <stdlib.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	words_count(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (!is_space(*str))
		{
			count++;
			while (*str && !is_space(*str))
				str++;
		}
		else
			str++;
	}
	return (count);
}

char	*get_word(char *str)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !is_space(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && !is_space(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int		i;
	char	**a_words;

	i = 0;
	a_words = (char **)malloc(sizeof(char *) * (words_count(str) + 1));
	if (!a_words)
		return (NULL);
	while (*str)
	{
		if (!is_space(*str))
		{
			a_words[i] = get_word(str);
			i++;
			while (*str && !is_space(*str))
				str++;
		}
		else
			str++;
	}
	// '\0'
	a_words[i] = NULL;
	return (a_words);
}
