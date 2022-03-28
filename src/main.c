#include "philo.h"

int	check_argv(t_table *table)
{
	if (table->num_philo <= 0)
		return (1);
	else if (table->time_life <= 0)
		return (1);
	else if (table->time_eat <= 0)
		return (1);
	else if (table->time_sleep <= 0)
		return (1);
	else if (table->eat_count < 0)
		return (1);
	return (0);
}

int main(int argc, char *argv[])
{
	t_table	table;

	if (argc < 5 || 6 < argc)
	{
		printf("please input\n");
		return (1);
	}
	init(argc, argv, &table);
	if (check_argv(&table))
	{
		printf("check input\n");
		return (1);
	}
	init_philos(table);
    init_mutex(table);

	// printf("num_philo = %d\n", table.num_philo);
	// printf("time_life = %d\n", table.time_life);
	// printf("time_eat = %d\n", table.time_eat);
	// printf("time_sleep = %d\n", table.time_sleep);
	// printf("eat_count = %d\n", table.eat_count);
	return (0);
}