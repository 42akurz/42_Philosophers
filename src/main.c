/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:56:21 by akurz             #+#    #+#             */
/*   Updated: 2021/10/19 13:42:04 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_input	*input;
	t_philo	*philo;

	input = malloc(sizeof(t_input));
	if (input == 0)
		return (-1);
	if (ft_parse(argc, argv, input) == -1)
		return (-1);
	if (ft_check_negative(input, argv) == -1)
		return (-1);
	if (ft_allocate_forks(input) == -1)
		return (-1);
	philo = ft_create_threads(input);
	if (philo == NULL)
		return (-1);
	ft_reaper(&philo);
	ft_join_destroy(philo);
	ft_free(input, philo);
	return (0);
}
