/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:13:14 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/06 12:25:28 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int		stack_a_len;

	stack_a_len = stacksize(stack_a);
	if (stack_a_len == 2)
	{
		swap(stack_a);
		print_action("sa");
	}
	else
	{
		insert_index(stack_a);
		if (stack_a_len == 3)
			sort_3nbr(stack_a);
		else
		{
			stacklen_big(stack_a, stack_b);
		}
	}
}

void	stack_creation(char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	char	**nums;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	nums = str_split(argv);
	if (!data_checker(nums))
	{
		memory_str_free(nums);
		write(2, "Error\n", 6);
		return ;
	}
	while (nums[i + 1])
		i++;
	while (i >= 0)
	{
		insert_nbr(&stack_a, ft_atoi(nums[i]));
		i--;
	}
	memory_str_free(nums);
	push_swap(&stack_a, &stack_b);
	memory_list_free(&stack_a);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		exit(EXIT_FAILURE);
	stack_creation(argv);
	return (0);
}
