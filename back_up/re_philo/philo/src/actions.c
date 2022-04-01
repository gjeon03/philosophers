#include "philo.h"

void	eating(t_philo *philo)
{
	uint64_t	time;
	
	time = get_time() - philo->start_time;
	pthread_mutex_lock(philo->msg);
	printf("%s%lld\t%d is eating\n", GREEN,\
		time, philo->philo_id);
	pthread_mutex_unlock(philo->msg);
	philo->last_eat = get_time();
	ft_sleep(philo->time_to_eat);
	(philo->eat_counter)++;
}

void	sleeping(t_philo *philo)
{
	uint64_t	time;
	
	time = get_time() - philo->start_time;
	pthread_mutex_lock(philo->msg);
	printf("%s%lld\t%d is sleeping\n", CYAN,\
		time, philo->philo_id);
	pthread_mutex_unlock(philo->msg);
	ft_sleep(philo->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	uint64_t	time;
	
	time = get_time() - philo->start_time;
	pthread_mutex_lock(philo->msg);
	printf("%s%lld\t%d is thinking\n", PURPLE,\
		time, philo->philo_id);
	pthread_mutex_unlock(philo->msg);
}

void	take_fork(t_philo *philo)
{
	uint64_t	time;
	
	time = get_time() - philo->start_time;
	pthread_mutex_lock(philo->msg);
	printf("%s%lld\t%d has take a fork\n", YELLOW,\
		time, philo->philo_id);
	pthread_mutex_unlock(philo->msg);
}

void	dead(t_philo *philo)
{
	uint64_t	time;
	
	time = get_time() - philo->start_time;
	pthread_mutex_lock(philo->msg);
	printf("%s%lld\t%d died\n", RED,\
		time, philo->philo_id);
}
