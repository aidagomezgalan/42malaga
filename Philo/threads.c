/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:19:24 by aidgomez          #+#    #+#             */
/*   Updated: 2024/04/08 20:42:21 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_ms_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	*monitor_routine(void *data)
{
	t_table	*table;

	table = (t_table *)data;
}

void	*thread_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->meals_count <= philo->table->meals_nbr || philo->died == 0)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	threads_init(t_table *table)
{
	int	i;

	i = 0;
	pthread_create(&table->monitor, NULL, monitor_routine, NULL);
	while (i < table->philos_nbr)
	{
		pthread_create(&table->a_philos[i].tid, NULL, thread_routine, NULL);
		i++;
	}
	i = 0;
	//pthread_join(&table->monitor, NULL);
	while (i < table->philos_nbr)
	{
		pthread_join(&table->a_philos[i].tid, NULL);
		i++;
	}
}
