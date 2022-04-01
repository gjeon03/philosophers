#include "philo.h"

int	main(int argc, char **argv)
{
	int			num_philos;
	t_philo		*philo;
	pthread_t	id;
	int			i;

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
	num_philos = ft_atoi(argv[1]);
	philo = malloc(num_philos * sizeof(t_philo));
	if (init_philo(philo, argv, argc, num_philos)) {
		printf("Please enter correct parameters\n");
		return (0);
	}
	if (argc == 6)
	{
		pthread_create(&id, NULL, &eat_count, philo);
		if (pthread_join(id, NULL) == 0)
			return (0);
	}
	i = 0;
	while (1)
	{
		if (!check_death(philo, num_philos))
			return (0);
	}
}
