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

typedef struct s_list
{
	int	philo;
	int	forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_nbr;
}t_list;

		// ARGS FUNCTIONS //
int		error_check(char **argv);
int		ft_atoi(const char *str);
int		number(char c);
void	assign(t_list *ph, int argc, char **argv);

#endif