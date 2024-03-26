/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:09:54 by aidgomez          #+#    #+#             */
/*   Updated: 2024/01/31 19:10:09 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacksize(t_list **stack)
{
	t_list	*temp;
	int		count;

	if (*stack == NULL)
		return (0);
	temp = *stack;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

void	b_move_cost(t_list **stack_b)
{
	t_list	*temp;
	int		stack_len;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	stack_len = stacksize(stack_b);
	while (temp)
	{
		if (temp->current_pos <= (stack_len - 1) / 2)
			temp->cost_b = temp->current_pos;
		else
			temp->cost_b = (stack_len - temp->current_pos) * -1;
		temp = temp->next;
	}
}

void	a_move_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;
	t_list	*temp_a;
	int		stack_len;

	temp_b = *stack_b;
	stack_len = stacksize(stack_a);
	while (temp_b)
	{
		temp_a = *stack_a;
		while (temp_a)
		{
			if (temp_b->target_pos == temp_a->current_pos)
			{
				if (temp_a->current_pos <= (stack_len - 1) / 2)
					temp_b->cost_a = temp_a->current_pos;
				else
					temp_b->cost_a = (stack_len - temp_a->current_pos) * -1;
				break ;
			}
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
}

int	total_move_cost(t_list **stack_b)
{
	int		total_cost;
	int		abs_cost_a;
	int		abs_cost_b;
	t_list	*temp;

	temp = *stack_b;
	if (temp->cost_a < 0)
		abs_cost_a = temp->cost_a * -1;
	else
		abs_cost_a = temp->cost_a;
	if (temp->cost_b < 0)
		abs_cost_b = temp->cost_b * -1;
	else
		abs_cost_b = temp->cost_b;
	total_cost = abs_cost_a + abs_cost_b;
	return (total_cost);
}

int	cheapest_nbr(t_list **stack_b)
{
	t_list	*temp_b;
	int		cheapest_cost;
	int		nbr_to_move;

	temp_b = *stack_b;
	cheapest_cost = total_move_cost(&temp_b);
	nbr_to_move = temp_b->index;
	while (temp_b)
	{
		if (temp_b && cheapest_cost > total_move_cost(&temp_b))
		{
			cheapest_cost = total_move_cost(&temp_b);
			nbr_to_move = temp_b->index;
		}
		temp_b = temp_b->next;
	}
	return (nbr_to_move);
}
