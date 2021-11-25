/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:56:03 by akurz             #+#    #+#             */
/*   Updated: 2021/11/23 20:55:00 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_print(char c, t_philo *philo)
{
	unsigned long	time;

	pthread_mutex_lock(&philo->input->print_lock);
	time = ft_get_time() - philo->input->start_time;
	if (c == 'F' && (philo->input->die_please != 1))
		printf("%ld    %d    %s\n", time, philo->philo_id, FORK);
	else if (c == 'E' && (philo->input->die_please != 1))
		printf("%ld    %d    %s\n", time, philo->philo_id, EATS);
	else if (c == 'S' && (philo->input->die_please != 1))
		printf("%ld    %d    %s\n", time, philo->philo_id, SLEEPS);
	else if (c == 'T' && (philo->input->die_please != 1))
		printf("%ld    %d    %s\n", time, philo->philo_id, THINKS);
	else if (c == 'D')
		printf("%ld    %d    %s\n", time, philo->philo_id, DIED);
	if (c != 'D')
		pthread_mutex_unlock(&philo->input->print_lock);
}

unsigned long	ft_get_time(void)
{
	unsigned long	time;
	struct timeval	t;

	gettimeofday(&t, NULL);
	time = (t.tv_sec * 1000);
	time += (t.tv_usec / 1000);
	return (time);
}

void	ft_usleep(unsigned long time, int num_ph)
{
	unsigned long	starttime;

	starttime = ft_get_time();
	if (num_ph > 50)
	{
		while (starttime + time > ft_get_time())
			usleep(200);
	}
	else
	{
		while (starttime + time > ft_get_time())
			usleep(50);
	}
	return ;
}
