/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:15:47 by aidgomez          #+#    #+#             */
/*   Updated: 2024/04/15 00:16:37 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_meals(t_table *table)
{
	pthread_mutex_lock(&table->end);
	if (table->total_meals == table->philos_nbr)
		table->end_dinner = 1;
	pthread_mutex_unlock(&table->end);
}

int	is_end_dinner(t_table *table)
{
	pthread_mutex_lock(&table->end);
	if (table->end_dinner == 0)
	{
		pthread_mutex_unlock(&table->end);
		return (0);
	}
	pthread_mutex_unlock(&table->end);
	return (1);
}
