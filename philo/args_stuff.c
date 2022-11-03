/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:07:14 by slaajour          #+#    #+#             */
/*   Updated: 2022/10/31 12:26:24 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] <= 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

int	error_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		// if (ft_atoi(argv[i]) == 0)
		// 	return (1);
		// if (ft_atoi(argv[i][0]) == 0)
		// 	return (1);
		j = 0;
		// if (argv[i][0] == '+' && argv[i][1] != '\0')
		// 	j++;
		while (argv[i][j])
		{
			if (!(number(argv[i][j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	assign(t_list *ph, int argc, char **argv)
{
	ph->philo = ft_atoi(argv[1]);
	ph->forks = ph->philo;
	ph->time_to_die = ft_atoi(argv[2]);
	ph->time_to_eat = ft_atoi(argv[3]);
	ph->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		ph->times_nbr = ft_atoi(argv[5]);
}
