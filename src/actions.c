#include "philo.h"

void	take_forks(t_philos *philo)
{
	write(1, "yo\n", 3);
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
		// make_eat(philo);
		// make_sleep(philo);
		// make_think(philo);
	}
	return (NULL);
}