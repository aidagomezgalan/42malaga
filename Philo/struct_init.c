/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:43:09 by aidgomez          #+#    #+#             */
/*   Updated: 2024/04/08 19:43:43 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	table_init(char **argv)
{
	t_table	*table;

	if (argv[5])
		table->meals_nbr = ft_atol(argv[5]);
	else
		table->meals_nbr = -1;
	table->philos_nbr = ft_atol(argv[1]);
	table->death_time = ft_atol(argv[2]);
	table->eat_time = ft_atol(argv[3]);
	table->sleep_time = ft_atol(argv[4]);
	pthread_mutex_init(&table->lock, NULL);
}

void	forks_init(t_table	*table)
{
	int		i;
	t_fork	*forks;

	i = 0;
	forks = table->a_forks;
	while (i < table->philos_nbr)
	{
		forks[i].id = i;
		forks[i].in_use = 0;
		pthread_mutex_init(&forks[i].mfork, NULL);
		i++;
	}
}

void	philos_init(t_table	*table)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = table->a_philos;
	while (i < table->philos_nbr)
	{
		philos[i].id = i + 1;
		philos[i].meals_count = 0;
		philos[i].died = 0;
		philos[i].table = table;
		if (philos[i].id == table->philos_nbr)
			philos[i].l_fork->id = 0;
		else
			philos[i].l_fork->id = philos[i].id;
		philos[i].r_fork->id = i;
		i++;
	}
}
