/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:06:54 by slaajour          #+#    #+#             */
/*   Updated: 2022/11/11 04:33:15 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create(t_list *info)
{
	int	i;
	int	j;

	i = 0;
	init(info);
	while (i < info->num_philo)
	{	
		info->ph[i].id = i + 1;
		info->ph[i].data = info;
		info->ph[i].right_fork = (i + 1) % info->num_philo;
		info->ph[i].left_fork = i;
		info->ph[i].provi = 0;
		pthread_create(&info->ph[i].t1, NULL, &routine, &info->ph[i]);
		i++;
		usleep(90);
	}
	optional(info);
	j = 0;
	while (j < info->num_philo)
	{
		pthread_mutex_destroy(&info->mutex[j]);
		j++;
	}
	pthread_mutex_destroy(info->pro);
}

int	norm(t_list *info)
{
	int	try;

	try = 0;
	pthread_mutex_lock(info->pro);
	if (info->meals / info->eating_times == info->num_philo)
		try = 1;
	pthread_mutex_unlock(info->pro);
	if (try == 1)
		return (0);
	return (1);
}

void	optional(t_list *info)
{
	int		i;

	i = 0;
	while (1)
	{
		if (!(norm(info)) && info->eating_times != -1)
			return ;
		pthread_mutex_lock(info->pro);
		if (ft_gettime() - info->time - info->ph[i].provi >= info->time_to_die)
		{
			pthread_mutex_lock(info->protect);
			printf("\033[1;30m%ld %d died\n",
				ft_gettime() - info->time, info->ph[i].id);
			return ;
		}
		pthread_mutex_unlock(info->pro);
		i++;
		if (i == info->num_philo)
			i = 0;
	}
}

int	main(int argc, char **argv)
{
	t_list	*info;

	if ((argc >= 5 && argc <= 6) && error_check(argv) == 0)
	{
		info = malloc(sizeof(t_list));
		if (!info)
			return (printf("Error in allocation of memory :)!\n"));
		assign(info, argc, argv);
		if (info->eating_times != 0)
			create(info);
	}
	else
		printf("Error in arguments :)!\n");
}
