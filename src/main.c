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

void	init_table(int argc, char *argv[], t_table *table)
{
	table->num_philo = ft_atoi(argv[1]);
	table->time_life = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->eat_count = ft_atoi(argv[5]);
	else
		table->eat_count = 0;
}

void	*thread_start(void *data)
{
	(void)data;
	printf("hello\n");
	return ("wwww\n");
}

int	create_table(t_table *table)
{
	pthread_t	*threads;
	int			i;
	char		*tmp;

	threads = malloc(sizeof(pthread_t) * (table->num_philo + 1));
	if (threads == NULL)
		return (-1);
	printf("create table\n");

	i = 0;
	tmp = 0;
	printf("table num : %d\n", table->num_philo);
	while (i < table->num_philo)
	{
		if (pthread_create(&(threads[i]), NULL,
				thread_start, &tmp) != 0)
			return (-1);
		i++;
		// printf("tmp: %s\n", tmp);
	}
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
	init_table(argc, argv, &table);
	if (check_argv(&table))
	{
		printf("check input\n");
		return (1);
	}
	create_table(&table);

	// printf("num_philo = %d\n", table.num_philo);
	// printf("time_life = %d\n", table.time_life);
	// printf("time_eat = %d\n", table.time_eat);
	// printf("time_sleep = %d\n", table.time_sleep);
	// printf("eat_count = %d\n", table.eat_count);
	return (0);
}