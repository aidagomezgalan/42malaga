/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:13:06 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/06 12:24:40 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

// typedef: creates an alias of the "struct s_list" data type
// t_list: Alias that replaces "struct s_list"
typedef struct s_list
{
	int				value;
	int				index;
	int				target_pos;
	int				current_pos;
	int				cost_b;
	int				cost_a;
	struct s_list	*next;
}					t_list;

// datachecker.c
int		data_checker(char **nums);
char	**str_split(char **argv);

// stack_commands.c
void	push(t_list **src, t_list **dest);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	print_action(char *stack_action);

// stack_actions.c
void	insert_nbr(t_list **stack, int nbr);
void	insert_index(t_list **stack);
void	insert_target_pos(t_list **stack_a, t_list **stack_b);
void	insert_current_pos(t_list **stack);

// utils.c
int		closed_a_index(t_list **stack_a, int index_b);
void	memory_str_free(char **temp);
void	memory_list_free(t_list **stack);
char	*ft_strjoin_free(char *s1, char *s2);

// stack_commands_actions.c
void	reverse_stacks(t_list **stack_a, t_list **stack_b, t_list *temp_b);
void	rotate_stacks(t_list **stack_a, t_list **stack_b, t_list *temp_b);
void	final_sort(t_list **stack_a);
void	update_stacks(t_list **stack_a, t_list **stack_b);

// movement_cost.c
void	b_move_cost(t_list **stack_b);
void	a_move_cost(t_list **stack_a, t_list **stack_b);
int		total_move_cost(t_list **stack_b);
int		cheapest_nbr(t_list **stack_b);
int		stacksize(t_list **stack);

// sort_stack.c
void	sort_3nbr(t_list **stack_a);
void	sort_big(t_list **stack_a, t_list **stack_b);
void	stacklen_big(t_list **stack_a, t_list **stack_b);

#endif
