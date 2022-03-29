#include "philo.h"

void	*make_actions(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&(philo->forks[philo->philo_id - 1]));
		take_fork(philo);
		pthread_mutex_lock(&(philo->forks[philo->philo_id % philo->num_philos]));
		eating(philo);
		pthread_mutex_unlock(&(philo->forks[philo->philo_id - 1]));
		pthread_mutex_unlock(&(philo->forks[philo->philo_id % philo->num_philos]));
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
				destroy_mutexes(philo->forks, philo->msg, philo->num_philos);
				return (NULL);
			}
			i++;
		}
	}
}
