/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:20:03 by aidgomez          #+#    #+#             */
/*   Updated: 2024/04/18 21:23:18 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo	*philo)
{
	picking_forks(philo);
	if (philo->nbr_forks == 2)
	{
		print_msg(philo, "is eating");
		philo->state = 'e';
		set_last_meal(philo);
		time_counter(philo, philo->table->eat_time);
		set_meals(philo);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		philo->nbr_forks = 0;
	}
	else
	{
		if (!is_end_dinner(philo->table))
		{
			if (philo->lfork_in_use)
				pthread_mutex_unlock(philo->l_fork);
			if (philo->rfork_in_use)
				pthread_mutex_unlock(philo->r_fork);
			philo_death(philo);
		}
	}
}

void	sleeping(t_philo *philo)
{
	print_msg(philo, "is sleeping");
	philo->state = 's';
	time_counter(philo, philo->table->sleep_time);
}

void	thinking(t_philo *philo)
{
	print_msg(philo, "is thinking");
	philo->state = 't';
}

void	*thread_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (!is_end_dinner(philo->table))
	{
		eating(philo);
		if (!is_end_dinner(philo->table))
			sleeping(philo);
		if (!is_end_dinner(philo->table))
			thinking(philo);
	}
	return (NULL);
}
