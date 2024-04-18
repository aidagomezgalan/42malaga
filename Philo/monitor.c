/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:15:47 by aidgomez          #+#    #+#             */
/*   Updated: 2024/04/18 21:47:56 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_death(t_philo *philo)
{
	print_msg(philo, "died");
	pthread_mutex_lock(&philo->table->end);
	philo->table->end_dinner = 1;
	pthread_mutex_unlock(&philo->table->end);
}

void	check_meals(t_table *table)
{
	pthread_mutex_lock(&table->end);
	if (table->total_meals == table->philos_nbr || table->meals_nbr == 0)
		table->end_dinner = 1;
	pthread_mutex_unlock(&table->end);
}

void	check_death_time(t_table *table)
{
	int		i;
	long	rest_time;
	long	time_to_die;

	i = 0;
	while (i++ < table->philos_nbr)
	{
		pthread_mutex_lock(&table->meals_lock);
		if (table->a_philos[i].state == 't')
			rest_time = (table->a_philos[i].last_meal + table->death_time);
		else if (table->a_philos[i].state == 'e')
			rest_time = (table->a_philos[i].last_meal + table->eat_time);
		else if (table->a_philos[i].state == 's')
			rest_time = table->sleep_time - time_to_die;
		time_to_die = (table->a_philos[i].last_meal + table->death_time);
		pthread_mutex_unlock(&table->meals_lock);
		while (rest_time - get_ms_time() >= 0)
		{
			if (time_to_die - get_ms_time() == 0)
			{
				philo_death(&table->a_philos[i]);
				return ;
			}
		}
	}
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
