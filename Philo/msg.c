/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:14:34 by aidgomez          #+#    #+#             */
/*   Updated: 2024/04/14 20:49:50 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	routine_time(long init_time)
{
	long	current_time;

	current_time = get_ms_time();
	return (current_time - init_time);
}

void	print_msg(t_philo *philo, char *str)
{
	if (!is_end_dinner(philo->table))
	{
		pthread_mutex_lock(&philo->table->print_lock);
		printf("%ld %i %s\n", routine_time(philo->table->init_time),
			philo->id, str);
		pthread_mutex_unlock(&philo->table->print_lock);
	}
}

void	error_msg(t_table *table, char *str)
{
	if (!is_end_dinner(table))
	{
		pthread_mutex_lock(&table->end);
		printf("ERROR!! %s\n", str);
		table->end_dinner = 1;
		pthread_mutex_unlock(&table->end);
	}
}
