/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:06:54 by slaajour          #+#    #+#             */
/*   Updated: 2022/10/31 12:19:54 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	mutex_init(t_list *info)
{
	int i;

	info->mutex = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (!info->mutex)
		return(printf("Error in allocation of memory :)!\n"));
	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_init(&info->mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&info->protect, NULL);
}

void	create(t_ph *philo, t_list *info)
{
	int i;

	i = 0;
	info->time = ft_gettime();
	while (i < info->num_philo)
	{
		philo[i].id = i + 1;
		philo[i].right_fork = (i + 1) % info->num_philo;
		philo[i].left_fork = i;
		philo[i].eating_times = 0;
		philo[i].info = info;
		if (pthread_create(&philo[i].t1, NULL, &routine, &philo[i]) != 0)
			return(printf("Error in creating the threads\n"));
		i++;
		usleep(90);
	}
	optional(info, philo);
}

int	optional(t_list *info, t_ph *philo)
{
	int		try;
	int		i;

	i = 0;
	try = 0;
	if (info->meals / info->eating_times == info->num_philo)
		try = 1;
	while (1)
	{
		if (try == 0 && info->eating_times != -1)
			return ;
		if ((ft_gettime() - info.info->time) - (info.provi) >= info.info->time_to_die)
		{
			pthread_mutex_lock(info_protect);
			hh_mout(philo);
			return ;
		}
		i++;
		if (i == info->num_philo)
			i = 0;
	}
}

int	main(int argc, char **argv)
{
	t_ph	*philo;
	t_list	*info;

	if ((argc >= 5 && argc <= 6) && error_check(argv) == 0)
	{
		philo = malloc(sizeof(t_ph) * ft_atoi(argv[1]));
		info = malloc(sizeof(t_list));
		if (!philo || !info)
			return(printf("Error in allocation of memory :)!\n"));
		assign(philo, argc, argv);
		mutex_init(info);
		create(philo, info);
	}
	else
		printf("Error in arguments :)!\n");
}
