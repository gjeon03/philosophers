#include "philo.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	if (argc < 5 || 6 < argc)
	{
		printf("Please enter parameters\n");
		printf("- number_of_philo\n");
		printf("- time_to_die\n");
		printf("- time_to_eat\n");
		printf("- time_to_sleep\n");
		printf("- [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	table.error_type = init(argc, argv, &table);
	if (table.error_type)
		return (destroy_table(&table));
	pthread_mutex_lock(&table.end_m);
	table.error_type = 6;
	return (destroy_table(&table));
}
