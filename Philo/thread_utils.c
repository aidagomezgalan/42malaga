/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:19:24 by aidgomez          #+#    #+#             */
/*   Updated: 2024/04/15 00:03:06 by aidgomez         ###   ########.fr       */
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
	check_meals(philo->table);
}

void	philo_death(t_philo *philo)
{
	print_msg(philo, "died");
	pthread_mutex_lock(&philo->table->end);
	philo->table->end_dinner = 1;
	pthread_mutex_unlock(&philo->table->end);
}

void	time_counter(t_philo *philo, int time, long *time_to_death)
{
	long	end_routine;

	end_routine = get_ms_time() + time;
	*time_to_death += philo->table->death_time;
	while (get_ms_time() < end_routine)
	{
		if (is_end_dinner(philo->table))
			return ;
		if (get_ms_time() >= *time_to_death)
		{
			philo_death(philo);
			return ;
		}
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

void	picking_forks(t_philo *philo, long *time_to_death)
{
	while (philo->nbr_forks != 2)
	{
		if (philo->table->philos_nbr == 1)
		{
			pick_fork(philo, philo->l_fork, &philo->lfork_in_use);
			while (get_ms_time() < *time_to_death)
				;
			break ;
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
		if (get_ms_time() >= *time_to_death)
			return ;
	}
	*time_to_death = get_ms_time() + philo->table->death_time;
}
