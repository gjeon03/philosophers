#include "philo.h"

void	init_mutex(t_table *table)
{
}

void	init_philos(t_table *table)
{
	int i;

	i = -1;
	while (++i < table->num_philo)
	{
		table->philos[i]->start_eat = 0;
		table->philos[i]->pos = i;
		table->philos[i]->fork_left = i;
		table->philos[i]->fork_right = (i + 1) % table->num_philo;
		table->philos[i]->eat_count = 0;
		table->philos[i]->table = table;
		pthread_mutex_init(&table->philos[i]->mutex, NULL);
		pthread_mutex_init(&table->philos[i]->eat_m, NULL);
		pthread_mutex_lock(&table->philos[i]->eat_m);
	}
}

void	init(t_table *table)
{
	table->num_philo = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->eat_count = ft_atoi(argv[5]);
	else
		table->eat_count = 0;
	table->forks = NULL;
	table->philos = NULL;
	table->philos = (t_philos *)malloc(sizeof(*(table->philos)) * table->num_philo);
	if (!table->philos)
		ft_error(0, table);
}