#include "philo.h"
int	init_data(t_philo *philo, char **argv, int argc)
{
	philo->num_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->num_of_eat = ft_atoi(argv[5]);
	else
		philo->num_of_eat = 0;
	if (check_argv(philo))
		return (1);
	return (0);
}

void	init_forks(pthread_mutex_t *forks, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_init(&(forks[i]), NULL);
		i++;
	}
}

void	create_threads(t_philo *philo, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_create(&(philo[i].thread_id), NULL, &make_actions, &(philo[i]));
		usleep(100);
		i++;
	}
	// usleep(100);
	// i = 1;
	// while (i < num_philos)
	// {
	// 	pthread_create(&(philo[i].thread_id), NULL, &make_actions, &(philo[i]));
	// 	i += 2;
	// }
}

int	init_philo(t_philo *philo, char **argv, int argc, int num_philos)
{
	int				i;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*msg;

	if (num_philos <= 0)
		return (1);
	msg = malloc(1 * sizeof(pthread_mutex_t));
	pthread_mutex_init(msg, NULL);
	forks = malloc(num_philos * sizeof(pthread_mutex_t));
	init_forks(forks, num_philos);
	i = 0;
	while (i < num_philos)
	{
		if (init_data(&(philo[i]), argv, argc))
			return (1);
		philo[i].eat_counter = 0;
		philo[i].forks = forks;
		philo[i].last_eat = get_time();
		philo[i].philo_id = i + 1;
		philo[i].msg = msg;
		philo[i].start_time = get_time();
		i++;
	}
	create_threads(philo, num_philos);
	return (0);
}
