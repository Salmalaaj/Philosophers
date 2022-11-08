#include "philosophers.h"

void    hh_mout(t_ph *philo)
{
	pthread_mutex_lock(philo->info->protect);
    printf("\033[1;30m%ld ms : Philo %d has taken a fork\n", ft_gettime() - philo->info->time, philo->id);

}

void    eat_plz(t_ph *philo)
{
	pthread_mutex_lock(&philo->info->mutex[philo->left_fork]);
	pthread_mutex_lock(philo->info->protect);
    printf("\033[1;31m%ld ms : Philo %d has taken a fork\n", ft_gettime() - philo->info->time, philo->id);
    pthread_mutex_unlock(philo->info->protect);
    pthread_mutex_lock(&philo->info->mutex[philo->right_fork]);
	pthread_mutex_lock(philo->info->protect);
    printf("\033[1;31m%ld ms : Philo %d has taken a fork\n", ft_gettime() - philo->info->time, philo->id);
    pthread_mutex_unlock(philo->info->protect);
	pthread_mutex_lock(philo->info->protect);
	printf("\033[1;32m%ld ms philo %d is eating\n", ft_gettime() - philo->info->time, philo->id);
    philo->provi = ft_gettime() - philo->info->time;
    if (philo->info->eating_times != -1)
        philo->info->meals++;
    pthread_mutex_unlock(philo->info->protect);
    pthread_mutex_unlock(&philo->info->mutex[pilo->left_fork]);
    pthread_mutex_unlock(&philo->info->mutex[pilo->right_fork]);
    ft_usleep(philo->info->time_to_eat);
}

void    sleep_plz(t_ph *philo)
{
	pthread_mutex_lock(philo->info->protect);
	printf("\033[1;33m%ld ms philo %d is sleeping\n", ft_gettime() - philo->info->time, philo->id);
	pthread_mutex_unlock(philo->info->protect);
	ft_usleep(philo->info->time_to_sleep);
}

void    think_plz(t_ph *philo)
{
    pthread_mutex_lock(philo->info->protect);
	printf("\033[1;34m%ld ms philo %d is thinking\n", ft_gettime() - philo->info->time, philo->id);
	pthread_mutex_unlock(philo->info->protect);
}

void    *routine(void *arg)
{
    t_ph  *philo;

    philo = (t_philo *)arg;
    while (1)
    {
        eat_plz(philo);
        sleep_plz(philo);
        think_plz(philo);
    }
    return (NULL);
}