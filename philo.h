/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:08:22 by akurz             #+#    #+#             */
/*   Updated: 2021/10/19 12:41:38 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

# define FORK "has taken a fork"
# define EATS "is eating"
# define SLEEPS "is sleeping"
# define THINKS "is thinking"
# define DIED "died"

typedef struct s_input
{
	int					num_ph;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					total_meals;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		fed_up_lock;
	pthread_mutex_t		wait_lock;
	unsigned long		start_time;
	int					wait_flag;
	int					fed_up;
	int					die_please;
	int					i;
}			t_input;

typedef struct s_philo
{
	pthread_t		thread;
	int				philo_id;
	int				meal_count;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	unsigned long	death_clock;
	t_input			*input;
}			t_philo;

// PARSE

int				ft_parse(int argc, char **argv, t_input *input);
int				ft_check_negative(t_input *input, char **argv);

// ALLOCATE

int				ft_allocate_forks(t_input *input);
t_philo			*ft_allocate_philos(t_input *input);

// INIT
void			ft_init(t_input *input, t_philo *philo);
void			ft_initialize_forks(t_philo *philo, int i);

// HELPER

void			ft_print(char c, t_philo *philo);
unsigned long	ft_get_time(void);
void			ft_usleep(unsigned long time, int num_ph);

// REAPER

void			ft_reaper(t_philo	**philo);

// ACTIONS

void			ft_eat(t_philo *philo);
void			ft_sleep(t_philo philo);

// JOIN DESTROY

void			ft_join_destroy(t_philo *philo);

// THREADS

t_philo			*ft_create_threads(t_input *input);

// FREE

void			ft_free(t_input	*input, t_philo *philo);

#endif
