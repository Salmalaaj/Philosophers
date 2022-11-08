/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:06:49 by slaajour          #+#    #+#             */
/*   Updated: 2022/10/31 12:17:54 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_list
{
	int	num_philo;
	int	num_forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eating_times;
	int end;
	int	time;
	int meals;
	pthread_mutex_t	*mutex;
	pthread_mutex_t *protect;
	t_ph	*philo;
}t_list;

typedef struct s_ph
{
	int	id;
    int right_fork;
    int left_fork;
	int last;
	int provi;
	pthread_t t1;
	t_list *info;
}   t_ph;

		// ARGS FUNCTIONS //
int		error_check(char **argv);
int		ft_atoi(const char *str);
int		number(char c);
void	assign(t_list *ph, int argc, char **argv);

		// PHILOOOO //
void	mutex_init(t_list *info);
void	create(t_ph *philo, t_list *info);

		// TIMING FUNCTIONS //
long	ft_gettime();
void	ft_usleep(int micro);

		// ROUTINE FUNCTIONS //
void    *routine(void);
void    eat_plz(t_ph *philo);
void    sleep_plz(t_ph *philo);
void    think_plz(t_ph *philo);
void    hh_mout(t_ph *philo);
int		optional(t_list *info, t_ph *philo);

#endif