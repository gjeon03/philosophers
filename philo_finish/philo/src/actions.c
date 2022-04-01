/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:03:10 by gjeon             #+#    #+#             */
/*   Updated: 2022/03/30 14:03:13 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	uint64_t	time;

	time = get_time() - philo->table->start_time;
	pthread_mutex_lock(philo->table->msg);
	printf("%lld\t%d is eating\n", \
		time, philo->philo_id);
	pthread_mutex_unlock(philo->table->msg);
	philo->last_eat = get_time();
	ft_sleep(philo->time_to_eat);
	(philo->eat_counter)++;
}

void	sleeping(t_philo *philo)
{
	uint64_t	time;

	time = get_time() - philo->table->start_time;
	pthread_mutex_lock(philo->table->msg);
	printf("%s%lld\t%d is sleeping\n", CYAN, \
		time, philo->philo_id);
	pthread_mutex_unlock(philo->table->msg);
	ft_sleep(philo->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	uint64_t	time;

	time = get_time() - philo->table->start_time;
	pthread_mutex_lock(philo->table->msg);
	printf("%s%lld\t%d is thinking\n", PURPLE, \
		time, philo->philo_id);
	pthread_mutex_unlock(philo->table->msg);
}

void	take_fork(t_philo *philo)
{
	uint64_t	time;

	time = get_time() - philo->table->start_time;
	pthread_mutex_lock(philo->table->msg);
	printf("%s%lld\t%d has take a fork\n", YELLOW, \
		time, philo->philo_id);
	pthread_mutex_unlock(philo->table->msg);
}

void	dead(t_philo *philo)
{
	uint64_t	time;

	time = get_time() - philo->table->start_time;
	pthread_mutex_lock(philo->table->msg);
	printf("%s%lld\t%d died\n", RED, \
		time, philo->philo_id);
}
