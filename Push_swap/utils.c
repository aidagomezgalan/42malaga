/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:12:06 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/02 15:41:46 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	big_a_index(t_list **stack_a)
{
	t_list	*temp_a;
	int		big_index_a;

	temp_a = *stack_a;
	big_index_a = temp_a->index;
	while (temp_a)
	{
		if (temp_a->index > big_index_a)
			big_index_a = temp_a->index;
		temp_a = temp_a->next;
	}
	return (big_index_a);
}

int	closed_a_index(t_list **stack_a, int index_b)
{
	t_list	*temp_a;
	int		closed_index;

	temp_a = *stack_a;
	closed_index = temp_a->index;
	if (index_b > big_a_index(stack_a))
	{
		while (temp_a)
		{
			if (temp_a->index < closed_index)
				closed_index = temp_a->index;
			temp_a = temp_a->next;
		}
	}
	else
	{
		closed_index = big_a_index(stack_a);
		while (temp_a)
		{
			if (temp_a->index > index_b && temp_a->index <= closed_index)
				closed_index = temp_a->index;
			temp_a = temp_a->next;
		}
	}
	return (closed_index);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * (sizeof(char)));
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	free(s1);
	i = 0;
	if (!s2)
		return (str);
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

void	memory_str_free(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

void	memory_list_free(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
