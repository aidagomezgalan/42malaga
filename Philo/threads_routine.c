/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:20:03 by aidgomez          #+#    #+#             */
/*   Updated: 2024/04/08 21:26:07 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->mfork);
	fork->in_use == 1;
	printf("[%ld] %i has taken a fork", get_ms_time(), philo->id);
}

void	drop_fork(t_fork *fork)
{
	fork->in_use == 0;
	pthread_mutex_unlock(&fork->mfork);
}

void	time_counter(int time)
{
	time_t	start;
	time_t	end;

	start = get_ms_time();
	end = get_ms_time() + time;
	while (get_ms_time() <= end)
		;
}

void	eating(t_philo	*philo)
{
	if (philo->id % 2 == 0 && philo->l_fork->in_use == 0)
	{
		pick_fork(philo, philo->l_fork);
		if (philo->r_fork->in_use == 0)
		{
			pick_fork(philo, philo->r_fork);
			eat_msg(philo->id);
			philo->meals_count++;
		}
	}
	else if (philo->id % 2 != 0 && philo->r_fork->in_use == 0)
	{
		pick_fork(philo, philo->r_fork);
		if (philo->l_fork->in_use == 0)
		{
			pick_fork(philo, philo->l_fork);
			eat_msg(philo->id);
			philo->meals_count++;
		}
	}
	time_counter(philo->table->eat_time);
	drop_fork(&philo->l_fork->mfork);
	drop_fork(&philo->r_fork->mfork);
	return ;
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	sleep_msg(philo->id);
	pthread_mutex_unlock(&philo->lock);
	time_counter(philo->table->sleep_time);
	return ;
}

void	thinking(t_philo *philo)
{
	int	think_time;

	think_time = philo->table->eat_time;
	pthread_mutex_lock(&philo->lock);
	think_msg(philo->id);
	pthread_mutex_unlock(&philo->lock);
	time_counter(think_time);
	return ;
}
