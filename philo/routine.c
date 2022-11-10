/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:49:59 by slaajour          #+#    #+#             */
/*   Updated: 2022/11/10 09:57:14 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(t_ph *philo, char *str, char *color)
{
	pthread_mutex_lock(philo->data->protect);
	printf("%s%ld %d %s\n", color,
		ft_gettime() - philo->data->time, philo->id, str);
	pthread_mutex_unlock(philo->data->protect);
}

void	eat_plz(t_ph *philo)
{
	pthread_mutex_lock(&philo->data->mutex[philo->left_fork]);
	print(philo, "has taken a fork", "\033[1;35m");
	pthread_mutex_lock(&philo->data->mutex[philo->right_fork]);
	print(philo, "has taken a fork", "\033[1;35m");
	print(philo, "is eating", "\033[1;36m");
	pthread_mutex_lock(philo->data->pro);
	if (philo->data->eating_times != -1)
		philo->data->meals++;
	pthread_mutex_unlock(philo->data->pro);
	philo->provi = ft_gettime() - philo->data->time;
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->mutex[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->mutex[philo->right_fork]);
}

void	sleep_plz(t_ph *philo)
{
	pthread_mutex_lock(philo->data->protect);
	printf("\033[1;34m%ld %d is sleeping\n",
		ft_gettime() - philo->data->time, philo->id);
	pthread_mutex_unlock(philo->data->protect);
	ft_usleep(philo->data->time_to_sleep);
}

void	think_plz(t_ph *philo)
{
	pthread_mutex_lock(philo->data->protect);
	printf("\033[1;33m%ld %d is thinking\n",
		ft_gettime() - philo->data->time, philo->id);
	pthread_mutex_unlock(philo->data->protect);
}

void	*routine(void *arg)
{
	t_ph	*ph;

	ph = (t_ph *)arg;
	while (1)
	{
		eat_plz(ph);
		sleep_plz(ph);
		think_plz(ph);
	}
	return (NULL);
}
