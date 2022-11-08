#include "philosophers.h"

long	ft_gettime()
{
	struct timeval	current_time;

	gettimeofday(&current_time, 0);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

// 1s = 1000ms
// 1s = 1000000us (microseconds)
// 1us = 0.001ms (10 puissance -3)
// micro to mili (nbr x 0.001)

void	ft_usleep(int micro)
{
	int	temps;

	temps = ft_gettime();
	while (ft_gettime() - temps < micro)
    	usleep(90);
}
