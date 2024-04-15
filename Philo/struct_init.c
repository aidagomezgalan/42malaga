/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:43:09 by aidgomez          #+#    #+#             */
/*   Updated: 2024/04/14 22:42:30 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_ms_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

t_table	table_init(char **argv)
{
	t_table	table;

	if (argv[5])
		table.meals_nbr = ft_atol(argv[5]);
	else
		table.meals_nbr = -1;
	table.philos_nbr = ft_atol(argv[1]);
	table.death_time = ft_atol(argv[2]);
	table.eat_time = ft_atol(argv[3]);
	table.sleep_time = ft_atol(argv[4]);
	table.init_time = get_ms_time();
	table.end_dinner = 0;
	table.total_meals = 0;
	safe_mutex_init(&table, &table.meals_lock);
	safe_mutex_init(&table, &table.print_lock);
	safe_mutex_init(&table, &table.end);
	return (table);
}

void	forks_init(t_table	*table)
{
	int	i;

	i = 0;
	table->a_forks = malloc(sizeof(t_mutex) * table->philos_nbr);
	if (!table->a_forks)
		error_msg(table, "Falló Malloc");
	while (i < table->philos_nbr)
	{
		safe_mutex_init(table, &table->a_forks[i]);
		i++;
	}
}

void	philos_init(t_table	*table)
{
	int	i;

	i = 0;
	table->a_philos = malloc(sizeof(t_philo) * table->philos_nbr);
	while (i < table->philos_nbr)
	{
		table->a_philos[i].id = i + 1;
		table->a_philos[i].meals_count = 0;
		table->a_philos[i].nbr_forks = 0;
		table->a_philos[i].lfork_in_use = 0;
		table->a_philos[i].rfork_in_use = 0;
		table->a_philos[i].last_meal = 0;
		table->a_philos[i].table = table;
		if (table->a_philos[i].id == table->philos_nbr)
			table->a_philos[i].l_fork = &table->a_forks[0];
		else
			table->a_philos[i].l_fork = &table->a_forks[i + 1];
		if (table->philos_nbr > 1)
			table->a_philos[i].r_fork = &table->a_forks[i];
		else
			table->a_philos[i].r_fork = NULL;
		i++;
	}
}
