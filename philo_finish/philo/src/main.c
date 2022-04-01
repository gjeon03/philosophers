/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:03:52 by gjeon             #+#    #+#             */
/*   Updated: 2022/03/30 14:03:54 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_msg(int flag)
{
	if (flag == 1)
	{
		printf("Please enter parameters\n");
		printf("- number_of_philo\n");
		printf("- time_to_die\n");
		printf("- time_to_eat\n");
		printf("- time_to_sleep\n");
		printf("- [number_of_times_each_philosopher_must_eat]\n");
	}
	else if (flag == 2)
	{
		printf("Please enter correct parameters\n");
	}
	return (0);
}

int	free_philo(t_table *table)
{
	free(table->forks);
	free(table->msg);
	free(table->philo);
	return (0);
}

int	main(int argc, char **argv)
{
	int			num_philos;
	t_table		table;
	pthread_t	id;
	int			i;

	if (argc < 5 || 6 < argc)
		return (error_msg(1));
	num_philos = ft_atoi(argv[1]);
	table.philo = malloc(num_philos * sizeof(t_philo));
	if (init_philo(&table, argv, argc, num_philos))
		return (error_msg(2));
	if (num_philos != 1 && argc == 6)
	{
		pthread_create(&id, NULL, &eat_count, table.philo);
		if (pthread_join(id, NULL) == 0)
			return (free_philo(&table));
	}
	i = 0;
	while (1)
	{
		if (!check_death(table.philo, num_philos))
			return (free_philo(&table));
		usleep(100);
	}
}
