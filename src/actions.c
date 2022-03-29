#include "philo.h"

void	make_sleep(t_philos *philo)
{
	if (philo->table->is_dead)
		return ;
	ft_print(philo, "is sleeping\n", 0, CYAN);
	pthread_mutex_unlock(&philo->table->forks_m[philo->fork_left]);
	if (philo->table->is_dead)
		return ;
	pthread_mutex_unlock(&philo->table->forks_m[philo->fork_right]);
	msleep(philo->table->time_sleep);
}

void	make_eat(t_philos *philo)
{
	if (philo->table->is_dead)
		return ;
	philo->is_eating = 1;
	philo->last_eat = get_time();
	ft_print(philo, "is eating\n", 0, GREEN);
	philo->eat_count++;
	if (philo->table->is_dead)
		return ;
	// philo->last_eat = get_time();
	msleep(philo->table->time_eat);
	if (philo->table->is_dead)
		return ;
	philo->is_eating = 0;
}

void	take_forks(t_philos *philo)
{
	if (philo->table->is_dead)
		return ;
	pthread_mutex_lock(&philo->table->forks_m[philo->fork_left]);
	ft_print(philo, "has taken a left fork\n", 0, YELLOW);
	if (philo->table->is_dead)
		return ;
	pthread_mutex_lock(&philo->table->forks_m[philo->fork_right]);
	ft_print(philo, "has taken a right fork\n", 0, YELLOW);
	if (philo->table->is_dead)
		return ;
}

void	*dead(void *philo_v)
{
	t_philos	*philo;

	philo = (t_philos *)philo_v;
	// usleep(100);
	while (1)
	{
		if (philo->table->is_dead)
			return (NULL);
		if (!philo->is_eating && \
		get_time() > philo->last_eat + philo->table->time_die)
		{
			ft_print(philo, "died\n", 1, RED);
			philo->table->is_dead = 1;
			pthread_mutex_unlock(&philo->table->end_m);
			return (0);
		}
		// usleep(100);
	}
	return (0);
}

void	*make_actions(void *philo_v)
{
	t_philos	*philo;
	pthread_t	tid;

	philo = (t_philos *)philo_v;
	philo->last_eat = philo->table->start;
	if (pthread_create(&tid, NULL, &dead, philo_v))
		return (NULL);
	pthread_detach(tid);
	while (1)
	{
		take_forks(philo);
		if (philo->table->is_dead)
			return (NULL);
		make_eat(philo);
		if (philo->table->is_dead)
			return (NULL);
		make_sleep(philo);
		if (philo->table->is_dead)
			return (NULL);
		ft_print(philo, "is thinking\n", 0, PURPLE);
	}
	return (NULL);
}
