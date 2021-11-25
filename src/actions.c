/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:04:41 by akurz             #+#    #+#             */
/*   Updated: 2021/11/23 18:02:08 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	ft_print('F', philo);
	if (philo->input->num_ph == 1)
	{
		ft_usleep(philo->input->time_die * 2, philo->input->num_ph);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	ft_print('F', philo);
	ft_print('E', philo);
	philo->death_clock = ft_get_time();
	ft_usleep(philo->input->time_eat, philo->input->num_ph);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	ft_sleep(t_philo philo)
{
	ft_print('S', &philo);
	ft_usleep(philo.input->time_sleep, philo.input->num_ph);
	ft_print('T', &philo);
}
