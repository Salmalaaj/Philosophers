/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:06:49 by slaajour          #+#    #+#             */
/*   Updated: 2022/11/10 10:00:16 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_ph
{
	int				id;
	int				right_fork;
	int				left_fork;
	int				provi;
	pthread_t		t1;
	struct s_list	*data;
}			t_ph;

typedef struct s_list
{
	int				num_philo;
	int				num_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eating_times;
	long int		time;
	int				meals;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*protect;
	pthread_mutex_t	*pro;
	t_ph			*ph;
}			t_list;

		// ARGS FUNCTIONS //
int			error_check(char **argv);
int			ft_atoi(const char *str);
int			number(char c);
void		assign(t_list *info, int argc, char **argv);

		// PHILOOOO //
void		create(t_list *info);
void		init(t_list *info);

		// TIMING FUNCTIONS //
long int	ft_gettime(void);
void		ft_usleep(long micro);

		// ROUTINE FUNCTIONS //
void		*routine(void *arg);
void		eat_plz(t_ph *philo);
void		sleep_plz(t_ph *philo);
void		think_plz(t_ph *philo);
void		optional(t_list *info);

#endif