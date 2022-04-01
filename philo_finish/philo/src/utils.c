/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:03:59 by gjeon             #+#    #+#             */
/*   Updated: 2022/03/30 14:04:01 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_argv(t_philo *philo)
{
	if (philo->time_to_eat <= 0)
		return (1);
	else if (philo->time_to_sleep <= 0)
		return (1);
	else if (philo->time_to_die <= 0)
		return (1);
	else if (philo->num_of_eat < 0)
		return (1);
	return (0);
}

uint64_t	get_time(void)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return (start.tv_sec * 1000 + start.tv_usec / 1000);
}

void	ft_sleep(uint64_t ms)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(100);
}

void	destroy_mutexes(pthread_mutex_t *forks, \
		pthread_mutex_t *msg, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_destroy(&(forks[i]));
		i++;
	}
	pthread_mutex_destroy(msg);
}

int	check_death(t_philo *philo, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		if ((int)(get_time() - philo[i].last_eat) > philo[i].time_to_die)
		{
			dead(&(philo[i]));
			destroy_mutexes(philo->table->forks, philo->table->msg, \
					philo->num_philos);
			return (0);
		}
	}
	return (1);
}
