/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:11:52 by slaajour          #+#    #+#             */
/*   Updated: 2022/11/01 15:17:56 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int mails = 0;
// int	lock = 0;
// mutex atomic variable 
pthread_mutex_t	mutex;

void*	routine()
{
	for(int i = 0; i < 10000000; i++)
	{
		pthread_mutex_lock(&mutex);
			// here we check if the lock has been taken by some thread
			// and waiting for the lock to unlock
			// also setting the lock to 1 once were done
		// if (lock == 1)
		// {
		// 	wait until the lock is 0
		// }
		// lock = 1;
		mails++;
		pthread_mutex_unlock(&mutex);
		// lock = 0;
	}
	return (0);
}

int main()
{
	pthread_t	arr[4];
	int i;
 
	// before using the mutex we need to initialize it
	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 4)
	{
		if (pthread_create(&arr[i], NULL, &routine, NULL) != 0)
			return 1;
		printf("Thread %d has started\n", i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(arr[i], NULL) != 0)
			return 2;
		printf("Thread %d has finished execution\n", i);
		i++;
	}
	// usleep(1500000);
	// init comes with a destroy (destroying the memory thats been allocated)
	pthread_mutex_destroy(&mutex);
	printf("%d\n", mails);
	gettimeofday()
}