/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:19:00 by akurz             #+#    #+#             */
/*   Updated: 2021/10/19 13:00:30 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_initialize_forks(t_philo *philo, int i)
{
	philo[i].philo_id = i + 1;
	philo[i].meal_count = 0;
	if (i == 0)
	{
		philo[i].right_fork = &philo->input->forks[philo->input->num_ph - 1];
		philo[i].left_fork = &philo->input->forks[i];
	}
	else
	{
		philo[i].right_fork = &philo->input->forks[i - 1];
		philo[i].left_fork = &philo->input->forks[i];
	}
}

void	ft_init(t_input *input, t_philo *philo)
{
	input->i = 0;
	pthread_mutex_init(&input->print_lock, NULL);
	pthread_mutex_init(&input->wait_lock, NULL);
	pthread_mutex_init(&input->fed_up_lock, NULL);
	while (input->i < input->num_ph)
	{
		philo[input->i].input = input;
		philo[input->i].meal_count = 0;
		philo[input->i].death_clock = 0;
		ft_initialize_forks(philo, input->i);
		pthread_mutex_init(philo[input->i].left_fork, NULL);
		input->i++;
	}
}
