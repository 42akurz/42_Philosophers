/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:10:36 by akurz             #+#    #+#             */
/*   Updated: 2021/10/18 19:05:23 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_join_destroy(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].input->num_ph)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
		{
			printf("Error\npthread_join\n");
			return ;
		}
		i++;
	}
	i = 0;
	while (i < philo[0].input->num_ph)
	{
		pthread_mutex_destroy(philo[i].left_fork);
		i++;
	}
	pthread_mutex_destroy(&philo[0].input->print_lock);
	pthread_mutex_destroy(&philo->input->wait_lock);
	pthread_mutex_destroy(&philo->input->fed_up_lock);
}
