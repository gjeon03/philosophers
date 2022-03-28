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
	philo->is_eating = 1;
	philo->last_eat = get_time();
	ft_print(philo, " is eating\n");
	philo->eat_count++;
	usleep(1000 * philo->table->time_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->eat_m);
}

void	take_forks(t_philos *philo)
{
	pthread_mutex_lock(&philo->table->forks_m[philo->fork_left]);
	ft_print(philo, " has taken a left fork\n");
	pthread_mutex_lock(&philo->table->forks_m[philo->fork_right]);
	ft_print(philo, " has taken a right fork\n");
}

void	*dead(void *philo_v)
{
	t_philos	*philo;

	philo = (t_philos *)philo_v;
	while (1)
	{
		if (!philo->is_eating && \
		getime() > philo->last_eat + philo->data->time_die)
		{
			ft_print(philo, " died\n");
			pthread_mutex_unlock(&philo->table->end_m);
		}
		usleep(1000);
	}
}

void	*make_actions(void *philo_v)
{
	t_philos	*philo;
	pthread_t	tid;

	philo = (t_philos *)philo_v;
	philo->last_eat = philo->table->start;
	if (pthread_create(&tid, NULL, &dead, philo_v))
		return (NULL);
	while (1)
	{
		take_forks(philo);
		make_eat(philo);
		make_sleep(philo);
		ft_print(philo, " is thinking\n");
	}
	return (NULL);
}
