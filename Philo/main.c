/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:50:57 by aidgomez          #+#    #+#             */
/*   Updated: 2024/04/15 00:16:12 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threads_init(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos_nbr)
	{
		safe_thread_create(table, i, thread_routine);
		i++;
	}
}

void	threads_end(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos_nbr)
	{
		pthread_join(table->a_philos[i].tid, NULL);
		i++;
	}
}

void	start_dinner(char **argv)
{
	t_table	table;

	table = table_init(argv);
	forks_init(&table);
	philos_init(&table);
	threads_init(&table);
	while (!is_end_dinner(&table))
		;
	threads_end(&table);
	printf("Todos han comido %i veces\n", table.meals_nbr);
	printf("THE DINNER IS OVER!!!!!\n");
	memory_mutex_free(&table);
}

int	main(int argc, char **argv)
{
	if (data_checker(argc, argv))
		start_dinner(argv);
	else
		printf("ERROR!! Wrong input. Almost 4 params\n");
	return (0);
}
