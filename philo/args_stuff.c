/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:07:14 by slaajour          #+#    #+#             */
/*   Updated: 2022/11/11 04:44:30 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	unsigned long	res;
	int				sign;
	int				i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	if (sign == 1 && res > 2147483647)
		return (-1);
	if (sign == -1 && res > 2147483648)
		return (-1);
	return ((int) res * sign);
}

int	error_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[1]) == 0 || ft_atoi(argv[i]) < 0)
			return (1);
		j = 0;
		if (argv[i][0] == '+' && argv[i][1] != '\0')
			j++;
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

void	assign(t_list *info, int argc, char **argv)
{
	info->num_philo = ft_atoi(argv[1]);
	info->num_forks = info->num_philo;
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->eating_times = -1;
	if (argc == 6)
		info->eating_times = ft_atoi(argv[5]);
}

void	init(t_list *info)
{
	int	j;

	j = 0;
	info->time = ft_gettime();
	info->ph = (t_ph *)malloc(sizeof(t_ph) * info->num_philo);
	info->mutex = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	info->protect = malloc(sizeof(pthread_mutex_t));
	info->pro = malloc(sizeof(pthread_mutex_t));
	info->meals = 0;
	if (!info->ph || !info->mutex || !info->protect || !info->pro)
		return ;
	while (j < info->num_philo)
	{
		pthread_mutex_init(&info->mutex[j], NULL);
		j++;
	}
	pthread_mutex_init(info->protect, NULL);
	pthread_mutex_init(info->pro, NULL);
}
