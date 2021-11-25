/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:50:49 by akurz             #+#    #+#             */
/*   Updated: 2021/10/19 13:45:55 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_routine(t_philo *philo)
{
	while (1)
	{
		ft_eat(philo);
		philo->meal_count++;
		if (philo->meal_count == philo->input->total_meals)
		{
			pthread_mutex_lock(&philo->input->fed_up_lock);
			philo->input->fed_up++;
			pthread_mutex_unlock(&philo->input->fed_up_lock);
			return ;
		}
		if (philo->input->die_please == 1)
			return ;
		ft_sleep(*philo);
	}
}

void	*ft_thread(void *var)
{
	t_philo			*philo;

	philo = (t_philo *)var;
	pthread_mutex_lock(&philo->input->wait_lock);
	if (philo->input->wait_flag == 0)
	{
		while (philo->input->i != philo->input->num_ph)
			continue ;
		philo->input->wait_flag = 1;
		philo->input->start_time = ft_get_time();
	}
	pthread_mutex_unlock(&philo->input->wait_lock);
	philo->death_clock = ft_get_time();
	if (philo->philo_id % 2 != 0)
		ft_usleep(philo->input->time_eat / 2, philo->input->num_ph);
	ft_routine(philo);
	return (NULL);
}

t_philo	*ft_create_threads(t_input *input)
{
	t_philo	*philo;

	philo = ft_allocate_philos(input);
	if (philo == 0)
	{
		printf("Error\nallocate_philos\n");
		return (NULL);
	}
	ft_init(input, philo);
	input->i = 0;
	while (input->i < input->num_ph)
	{
		if (pthread_create(&philo[input->i].thread, NULL,
				&ft_thread, &philo[input->i]) != 0)
		{
			printf("Error\npthread_create\n");
			return (NULL);
		}
		input->i++;
	}
	usleep(50000);
	return (philo);
}
