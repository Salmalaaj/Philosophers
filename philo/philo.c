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

int	main(int argc, char **argv)
{
	t_list	ph;

	if ((argc >= 5 && argc <= 6) && error_check(argv) == 0)
	{
		assign(&ph, argc, argv);
	}
	else
		printf("Error in arguments :)!\n");
}
