/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:07:02 by aidgomez          #+#    #+#             */
/*   Updated: 2024/04/08 21:25:00 by aidgomez         ###   ########.fr       */
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
	int		in_use;
	t_mutex	mfork;
}			t_fork;

typedef struct s_philo
{
	int			id;
	int			meals_count;
	int			died;
	t_table		*table;
	t_fork		*r_fork;
	t_fork		*l_fork;
	pthread_t	tid;
	t_mutex		lock;
}				t_philo;

typedef struct s_table
{
	int			meals_nbr;
	int			philos_nbr;
	int			death_time;
	int			eat_time;
	int			sleep_time;
	t_philo		*a_philos;
	t_fork		*a_forks;
	pthread_t	monitor;
	t_mutex		lock;
}				t_table;

// data_checker.c
int		data_checker(int argc, char **argv);

// struct_init.c
void	table_init(char **argv);
void	forks_init(t_table	*table);
void	philos_init(t_table	*table);

//threads_routine.c
void	eating(t_philo	*philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

//threads.c
void	threads_init(t_table *table);
time_t	get_ms_time(void);

// philo.c
int		main(int argc, char **argv);

// routine_msg.c
void	eat_msg(int philo_id);
void	sleep_msg(int philo_id);
void	think_msg(int philo_id);
void	died_msg(int philo_id);

#endif
