/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:14:34 by aidgomez          #+#    #+#             */
/*   Updated: 2024/04/08 21:25:37 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_msg(int philo_id)
{
	printf("[%ld] %i is eating", get_ms_time(), philo_id);
}

void	sleep_msg(int philo_id)
{
	printf("[%ld] %i is sleeping", get_ms_time(), philo_id);
}

void	think_msg(int philo_id)
{
	printf("[%ld] %i is thinking", get_ms_time(), philo_id);
}

void	died_msg(int philo_id)
{
	printf("[%ld] %i is died", get_ms_time(), philo_id);
}
