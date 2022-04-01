/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:03:33 by gjeon             #+#    #+#             */
/*   Updated: 2022/03/30 14:03:34 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*make_actions(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = philo->table->start_time;
	while (1)
	{
		pthread_mutex_lock(&(philo->table->forks[philo->philo_id - 1]));
		take_fork(philo);
		pthread_mutex_lock(&(philo->table->forks[philo->philo_id \
							% philo->num_philos]));
		eating(philo);
		pthread_mutex_unlock(&(philo->table->forks[philo->philo_id - 1]));
		pthread_mutex_unlock(&(philo->table->forks[philo->philo_id \
							% philo->num_philos]));
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	*eat_count(void *arg)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < philo[i].num_philos)
		{
			if (philo[i].eat_counter < philo[i].num_of_eat)
				break ;
			if (i == philo[i].num_philos - 1)
			{
				destroy_mutexes(philo->table->forks, philo->table->msg, \
						philo->num_philos);
				return (NULL);
			}
			i++;
		}
		usleep(100);
	}
}
