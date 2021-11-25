/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:57:46 by akurz             #+#    #+#             */
/*   Updated: 2021/10/19 12:56:39 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_specialchar(char c)
{
	if (c == ' ' || c == '\r' || c == '\n'
		|| c == '\t' || c == '\f' || c == '\b' || c == '\v')
		return (1);
	return (0);
}

long long	ft_atoi(const char *str)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_specialchar(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = (-1);
		i++;
	}
	while ((str[i] != '\0') && (str[i] - '0' >= 0 && str[i] - '0' <= 9))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	count;

	count = 0;
	while (count < n)
	{
		if ((unsigned char)str1[count] != (unsigned char)str2[count])
		{
			return ((unsigned char)str1[count] - (unsigned char)str2[count]);
		}
		if ((unsigned char)str1[count] == '\0'
			|| (unsigned char)str2[count] == '\0')
		{
			return (0);
		}
		count++;
	}
	return (0);
}

int	ft_check_negative(t_input *input, char **argv)
{
	if (input->num_ph < 0 || input->time_die < 0 || input->time_eat < 0
		|| input->time_sleep < 0 || input->total_meals < 0)
	{
		printf("Error\nNegative values\n");
		return (-1);
	}
	if ((input->time_die == 0 && (ft_strncmp(argv[2], "0", 1) != 0))
		|| (input->time_eat == 0 && (ft_strncmp(argv[3], "0", 1) != 0))
		|| (input->time_sleep == 0 && (ft_strncmp(argv[4], "0", 1) != 0))
		|| (input->total_meals == 0 && (ft_strncmp(argv[4], "0", 1) != 0)))
	{
		printf("Error\nWrong values!\n");
		return (-1);
	}
	return (0);
}

int	ft_parse(int argc, char **argv, t_input *input)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error\nwrong amount of args\n");
		return (-1);
	}
	input->num_ph = ft_atoi(argv[1]);
	if (input->num_ph == 0)
	{
		printf("No Philosopher at the table!\n");
		return (-1);
	}
	input->time_die = ft_atoi(argv[2]);
	input->time_eat = ft_atoi(argv[3]);
	input->time_sleep = ft_atoi(argv[4]);
	input->die_please = 0;
	input->start_time = 0;
	input->wait_flag = 0;
	input->fed_up = 0;
	input->die_please = 0;
	if (argc == 6)
		input->total_meals = ft_atoi(argv[5]);
	else
		input->total_meals = INT_MAX;
	return (0);
}
