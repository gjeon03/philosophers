#include "philo.h"

int	init_mutex(t_table *table)
{
	int	i;

	table->forks_m = (pthread_mutex_t *) \
	malloc(sizeof(pthread_mutex_t) * table->num_philo);
	if (!table->forks_m)
		return (2);
	i = -1;
	while (++i < table->num_philo)
	{
		if (pthread_mutex_init(&table->forks_m[i], NULL))
		{
			while (i--)
				pthread_mutex_destroy(&table->forks_m[i]);
			return (3);
		}
	}
	if (pthread_mutex_init(&table->write_m, NULL))
		return (4);
	if (pthread_mutex_init(&table->end_m, NULL))
		return (5);
	pthread_mutex_lock(&table->end_m);
	return (init_threads(table));
}

int	init_philos(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->num_philo)
	{
		table->philos[i].pos = i;
		table->philos[i].is_eating = 0;
		table->philos[i].fork_left = i;
		table->philos[i].fork_right = (i + 1) % table->num_philo;
		table->philos[i].eat_count = 0;
		table->philos[i].table = table;
	}
	return (init_mutex(table));
}

void	*eat_count(void *table_v)
{
	t_table	*table;
	int		count;
	int		i;

	table = (t_table *)table_v;
	while (1)
	{
		i = -1;
		count = 0;
		while (++i < table->num_philo)
			if (table->philos[i].eat_count >= table->eat_count)
				count++;
		if (count == table->num_philo)
		{
			ft_print(&table->philos[0], "", 2, NULL);
			table->is_dead = 1;
			// usleep(100);
			pthread_mutex_unlock(&table->end_m);
		}
		// usleep(100);
	}
	return (NULL);
}

int	init_threads(t_table *table)
{
	int			i;
	pthread_t	tid;

	table->start = get_time();
	i = -1;
	if (table->eat_count)
	{
		if (pthread_create(&tid, NULL, &eat_count, (void *)table))
			return (6);
		pthread_detach(tid);
	}
	while (++i < table->num_philo)
	{
		if (pthread_create(&tid, NULL, \
		&make_actions, (void *)(table->philos + i)))
			return (6);
		pthread_detach(tid);
		if (table->philos[i].pos % 2 == 0)
			usleep(100);
	}
	return (0);
}

int	init(int argc, char *argv[], t_table *table)
{
	table->forks_m = NULL;
	table->philos = NULL;
	table->num_philo = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	table->is_dead = 0;
	if (argc == 6)
		table->eat_count = ft_atoi(argv[5]);
	else
		table->eat_count = 0;
	if (check_argv(table))
	{
		printf("Please enter correct parameters\n");
		return (1);
	}
	table->forks_m = NULL;
	table->philos = NULL;
	table->philos = (t_philos *)malloc(sizeof(t_philos) * table->num_philo);
	if (!table->philos)
		return (1);
	return (init_philos(table));
}
