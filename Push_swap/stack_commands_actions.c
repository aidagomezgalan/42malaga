/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands_actions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:54:01 by aidgomez          #+#    #+#             */
/*   Updated: 2024/01/31 19:10:09 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_stacks(t_list **stack_a, t_list **stack_b, t_list *temp_b)
{
	if (!(*stack_a) || !(*stack_b) || !temp_b)
		return ;
	if (temp_b->cost_b < 0 && temp_b->cost_a < 0)
	{
		while (temp_b->cost_b < 0 && temp_b->cost_a < 0)
		{
			reverse_rotate(stack_a);
			reverse_rotate(stack_b);
			print_action("rrr");
			temp_b->cost_b++;
			temp_b->cost_a++;
		}
	}
	while (temp_b->cost_b < 0)
	{
		reverse_rotate(stack_b);
		print_action("rrb");
		temp_b->cost_b++;
	}
	while (temp_b->cost_a < 0)
	{
		reverse_rotate(stack_a);
		print_action("rra");
		temp_b->cost_a++;
	}
}

void	rotate_stacks(t_list **stack_a, t_list **stack_b, t_list *temp_b)
{
	if (!(*stack_a) || !(*stack_b) || !temp_b)
		return ;
	if (temp_b->cost_b > 0 && temp_b->cost_a > 0)
	{
		while (temp_b->cost_b > 0 && temp_b->cost_a > 0)
		{
			rotate(stack_a);
			rotate(stack_b);
			print_action("rr");
			temp_b->cost_b--;
			temp_b->cost_a--;
		}
	}
	while (temp_b->cost_b > 0)
	{
		rotate(stack_b);
		print_action("rb");
		temp_b->cost_b--;
	}
	while (temp_b->cost_a > 0)
	{
		rotate(stack_a);
		print_action("ra");
		temp_b->cost_a--;
	}
}

void	update_stacks(t_list **stack_a, t_list **stack_b)
{
	insert_current_pos(stack_b);
	insert_current_pos(stack_a);
	insert_target_pos(stack_a, stack_b);
	b_move_cost(stack_b);
	a_move_cost(stack_a, stack_b);
}

int	first_index(t_list **stack_a)
{
	t_list	*temp_a;

	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->index == 1)
			return (temp_a->current_pos);
		temp_a = temp_a->next;
	}
	return (temp_a->current_pos);
}

void	final_sort(t_list **stack_a)
{
	int		first_nbr;

	first_nbr = first_index(stack_a);
	if (first_nbr <= (stacksize(stack_a) - 1) / 2)
	{
		while (first_nbr-- >= 1)
		{
			rotate(stack_a);
			print_action("ra");
		}
	}
	else
	{
		first_nbr = stacksize(stack_a) - first_nbr;
		while (first_nbr-- >= 1)
		{
			reverse_rotate(stack_a);
			print_action("rra");
		}
	}
}
