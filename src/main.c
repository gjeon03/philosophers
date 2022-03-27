#include "philo.h"

int	check_argv(t_philo *philo)
{
	if (philo->philo_len <= 0)
		return (1);
	else if (philo->time_life <= 0)
		return (1);
	else if (philo->time_eat <= 0)
		return (1);
	else if (philo->time_sleep <= 0)
		return (1);
	else if (philo->end_flag < 0)
		return (1);
	return (0);
}

void	philo_init(char *argv[], t_philo *philo)
{
	philo->philo_len = ft_atoi(argv[1]);
	philo->time_life = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	philo->end_flag = ft_atoi(argv[5]);
}

int main(int argc, char *argv[])
{
	t_philo	philo;

	if (argc < 6 || argc > 6)
	{
		printf("please input\n");
		return (1);
	}
	philo_init(argv, &philo);

	if (check_argv(&philo))
	{
		printf("check input\n");
		return (1);
	}
	printf("philo_len = %d\n", philo.philo_len);
	printf("time_life = %d\n", philo.time_life);
	printf("time_eat = %d\n", philo.time_eat);
	printf("time_sleep = %d\n", philo.time_sleep);
	printf("end_flag = %d\n", philo.end_flag);
	return (0);
}