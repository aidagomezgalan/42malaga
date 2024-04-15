/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:20:03 by aidgomez          #+#    #+#             */
/*   Updated: 2024/04/14 23:51:19 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo	*philo)
{
	long	time_to_death;

	time_to_death = get_ms_time() + philo->table->death_time;
	picking_forks(philo, &time_to_death);
	if (philo->nbr_forks == 2)
	{
		print_msg(philo, "is eating");
		time_counter(philo, philo->table->eat_time, &time_to_death);
		set_meals(philo);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		philo->nbr_forks = 0;
		philo->last_meal = get_ms_time();
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

void	sleeping(t_philo *philo, long last_meal)
{
	print_msg(philo, "is sleeping");
	time_counter(philo, philo->table->sleep_time, &last_meal);
}

void	thinking(t_philo *philo)
{
	print_msg(philo, "is thinking");
}

void	*thread_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (!is_end_dinner(philo->table))
	{
		eating(philo);
		if (!is_end_dinner(philo->table))
			sleeping(philo, philo->last_meal);
		if (!is_end_dinner(philo->table))
			thinking(philo);
	}
	return (NULL);
}
