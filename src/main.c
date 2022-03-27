#include "philo.h"

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

	printf("philo_len = %d\n", philo.philo_len);
	printf("time_life = %d\n", philo.time_life);
	printf("time_eat = %d\n", philo.time_eat);
	printf("time_sleep = %d\n", philo.time_sleep);
	printf("end_flag = %d\n", philo.end_flag);
	return (0);
}