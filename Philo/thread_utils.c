/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:19:24 by aidgomez          #+#    #+#             */
/*   Updated: 2024/04/18 21:25:40 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_meals(t_philo *philo)
{
	if (!is_end_dinner(philo->table))
	{
		if (philo->table->meals_nbr > 0)
			philo->meals_count++;
		if (philo->meals_count == philo->table->meals_nbr)
		{
			pthread_mutex_lock(&philo->table->meals_lock);
			philo->table->total_meals += 1;
			pthread_mutex_unlock(&philo->table->meals_lock);
		}
	}
}

void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->meals_lock);
	philo->last_meal = get_ms_time();
	pthread_mutex_unlock(&philo->table->meals_lock);
}

void	time_counter(t_philo *philo, int time)
{
	long	end_routine;

	end_routine = get_ms_time() + time;
	while (get_ms_time() < end_routine)
	{
		if (is_end_dinner(philo->table))
			return ;
	}
}

void	pick_fork(t_philo *philo, t_mutex *fork, int *in_use)
{
	if (!is_end_dinner(philo->table) && fork)
	{
		*in_use = 0;
		pthread_mutex_lock(fork);
		print_msg(philo, "has taken a fork");
		if (philo->nbr_forks == 0)
			philo->nbr_forks = 1;
		else
			philo->nbr_forks = 2;
		*in_use = 1;
	}
}

void	picking_forks(t_philo *philo)
{
	if (philo->table->philos_nbr == 1)
	{
		pick_fork(philo, philo->l_fork, &philo->lfork_in_use);
		time_counter(philo, philo->table->death_time);
	}
	else if (philo->id % 2 == 0)
	{
		pick_fork(philo, philo->r_fork, &philo->rfork_in_use);
		pick_fork(philo, philo->l_fork, &philo->lfork_in_use);
	}
	else
	{
		pick_fork(philo, philo->l_fork, &philo->lfork_in_use);
		pick_fork(philo, philo->r_fork, &philo->rfork_in_use);
	}
}
