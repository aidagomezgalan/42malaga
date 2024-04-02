/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:07:02 by aidgomez          #+#    #+#             */
/*   Updated: 2024/03/31 22:43:32 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef pthread_mutex_t	t_mutex;
typedef struct s_table	t_table;

typedef struct s_fork
{
	int		id;
	t_mutex	tfork;
}			t_fork;

typedef struct s_philo
{
	int			id;
	int			meals_count;
	t_fork		*r_fork;
	t_fork		*l_fork;
	t_table		*table;
	pthread_t	t_id;
}				t_philo;

typedef struct s_table
{
	long	meals_nbr;
	long	philos_nbr;
	long	death_time;
	long	eat_time;
	long	sleep_time;
	t_philo	*a_philos;
	t_fork	*a_forks;
	t_mutex	*forks;
	t_mutex	lock;
}			t_table;

// data_checker.c
int	data_checker(int argc, char **argv);

// philo.c
int	main(int argc, char **argv);

#endif
