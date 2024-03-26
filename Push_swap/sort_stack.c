/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:42:19 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/06 12:40:56 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3nbr(t_list **stack_a)
{
	t_list	*temp_a;

	temp_a = *stack_a;
	if (temp_a->index > temp_a->next->index
		&& temp_a->index > temp_a->next->next->index)
	{
		rotate(stack_a);
		print_action("ra");
	}
	else if (temp_a->next->index > temp_a->index
		&& temp_a->next->index > temp_a->next->next->index)
	{
		reverse_rotate(stack_a);
		print_action("rra");
	}
	temp_a = *stack_a;
	if (temp_a->index > temp_a->next->index)
	{
		swap(stack_a);
		print_action("sa");
	}
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;

	temp_b = *stack_b;
	while (temp_b)
	{
		if (temp_b->index == cheapest_nbr(stack_b))
		{
			reverse_stacks(stack_a, stack_b, temp_b);
			rotate_stacks(stack_a, stack_b, temp_b);
			push(stack_b, stack_a);
			print_action("pa");
			return ;
		}
		temp_b = temp_b->next;
	}
}

void	stacklen_big(t_list **stack_a, t_list **stack_b)
{
	int		stack_a_len;

	stack_a_len = stacksize(stack_a);
	while (stack_a_len > 3)
	{
		push(stack_a, stack_b);
		print_action("pb");
		stack_a_len--;
	}
	sort_3nbr(stack_a);
	while (stacksize(stack_b))
	{
		update_stacks(stack_a, stack_b);
		sort_big(stack_a, stack_b);
	}
	insert_current_pos(stack_a);
	final_sort(stack_a);
}
