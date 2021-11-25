/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:55:45 by akurz             #+#    #+#             */
/*   Updated: 2021/10/18 19:04:06 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_reaper(t_philo	**philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if ((*philo)[i].input->fed_up == (*philo)[i].input->num_ph)
		{
			printf("THE END\n");
			return ;
		}
		if (ft_get_time()
			> (*philo)[i].death_clock + (*philo)[i].input->time_die)
		{
			(*philo)[i].input->die_please = 1;
			ft_print('D', (*philo));
			pthread_mutex_unlock(&(*philo)[i].input->print_lock);
			return ;
		}
		if (i == (*philo)[i].input->num_ph - 1)
			i = 0;
		if (((*philo)[i].input->num_ph) != 1)
			i++;
	}
}
