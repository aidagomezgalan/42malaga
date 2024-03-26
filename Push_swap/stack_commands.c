/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:11:54 by aidgomez          #+#    #+#             */
/*   Updated: 2024/01/31 19:10:09 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_action(char *stack_action)
{
	int	length;

	length = ft_strlen(stack_action);
	write(1, stack_action, length);
	write(1, "\n", 1);
}

void	push(t_list **src, t_list **dest)
{
	t_list	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*dest == NULL)
		temp->next = NULL;
	else
		temp->next = *dest;
	*dest = temp;
}

void	swap(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	if (*stack && (*stack)->next)
	{
		*stack = temp->next;
		temp->next = (*stack)->next;
		(*stack)->next = temp;
	}
}

void	rotate(t_list **stack)
{
	t_list	*last;
	t_list	*temp;

	if (*stack && (*stack)->next)
	{
		last = *stack;
		*stack = (*stack)->next;
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = last;
		last->next = NULL;
	}
}

void	reverse_rotate(t_list **stack)
{
	t_list	*prev;
	t_list	*first;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		prev = NULL;
		while (first->next)
		{
			prev = first;
			first = first->next;
		}
		prev->next = NULL;
		first->next = *stack;
		*stack = first;
	}
}
