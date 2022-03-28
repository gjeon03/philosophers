#include "philo.h"

void	make_sleep(t_philos *philo)
{
	ft_print(philo, " is sleeping\n");
	pthread_mutex_unlock(&philo->table->forks_m[philo->fork_left]);
	pthread_mutex_unlock(&philo->table->forks_m[philo->fork_right]);
	usleep(1000 * philo->table->time_sleep);
}

void	make_eat(t_philos *philo)
{
	pthread_mutex_lock(&philo->eat_m);
	philo->last_eat = get_time();
	ft_print(philo, " is eating\n");
	philo->eat_count++;
	usleep(1000 * philo->table->time_eat);
	pthread_mutex_unlock(&philo->eat_m);
}

void	take_forks(t_philos *philo)
{
	pthread_mutex_lock(&philo->table->forks_m[philo->fork_left]);
	ft_print(philo, " has taken a left fork\n");
	pthread_mutex_lock(&philo->table->forks_m[philo->fork_right]);
	ft_print(philo, " has taken a right fork\n");
}

void	*make_actions(void *philo_v)
{
	// t_philos	*philo;

	// philo = (t_philos *)philo_v;
	while (1)
	{
		take_forks(philo_v);
		make_eat(philo_v);
		make_sleep(philo_v);
		ft_print(philo_v, " is thinking\n");
		// make_think(philo);
	}
	return (NULL);
}