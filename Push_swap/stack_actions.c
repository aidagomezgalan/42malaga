/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:24:00 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/02 15:07:09 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_nbr(t_list **stack, int nbr)
{
	t_list	*temp;

	temp = (t_list *)malloc(sizeof(t_list));
	if (temp == NULL)
		return ;
	temp->value = nbr;
	temp->next = *stack;
	*stack = temp;
}

void	insert_index(t_list **stack)
{
	t_list	*temp;
	t_list	*current;
	int		count;

	if (*stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		count = 1;
		temp = *stack;
		while (temp)
		{
			if (temp->value < current->value)
				count++;
			temp = temp->next;
		}
		current->index = count;
		current = current->next;
	}
}

void	insert_current_pos(t_list **stack)
{
	int		i;
	t_list	*temp;

	i = 0;
	if (*stack == NULL)
		return ;
	temp = *stack;
	while (temp)
	{
		temp->current_pos = i;
		i++;
		temp = temp->next;
	}
}

void	insert_target_pos(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	temp_b = *stack_b;
	while (temp_b)
	{
		temp_a = *stack_a;
		while (temp_a)
		{
			if (temp_a->index == closed_a_index(stack_a, temp_b->index))
			{
				temp_b->target_pos = temp_a->current_pos;
				break ;
			}
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
}
