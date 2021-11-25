/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:46:40 by akurz             #+#    #+#             */
/*   Updated: 2021/10/18 18:42:22 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_allocate_forks(t_input *input)
{
	input->forks = malloc(sizeof(*input->forks) * input->num_ph);
	if (input->forks == 0)
	{
		printf("Error\nallocate_forks\n");
		return (-1);
	}
	return (0);
}

t_philo	*ft_allocate_philos(t_input *input)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * input->num_ph);
	return (philo);
}
