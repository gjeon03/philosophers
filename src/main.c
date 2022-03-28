#include "philo.h"

int	check_argv(t_table *table)
{
	if (table->num_philo <= 0)
		return (1);
	else if (table->time_die <= 0)
		return (1);
	else if (table->time_eat <= 0)
		return (1);
	else if (table->time_sleep <= 0)
		return (1);
	else if (table->eat_count < 0)
		return (1);
	return (0);
}

void	free_table(t_table *table)
{
	if (!table)
		;
}

void	ft_error(char *str, t_table *table)
{
	(void)table;
	printf("%s\n", str);
}

int	main(int argc, char *argv[])
{
	t_table	table;

	if (argc < 5 || 6 < argc)
	{
		ft_error("please input", &table);
		return (1);
	}
	init(argc, argv, &table);
	if (check_argv(&table))
	{
		ft_error("check input", &table);
		return (1);
	}
	init_philos(&table);
	init_mutex(&table);
	init_threads(&table);
	pthread_mutex_lock(&table.end_m);
	pthread_mutex_unlock(&table.end_m);
	return (0);
}
