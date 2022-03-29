#include "philo.h"

void	ft_print(t_philos *philo, char *msg, int is_dead, char *color)
{
	static int	finish = 0;

	pthread_mutex_lock(&philo->table->write_m);
	if (!finish)
	{
		if (is_dead)
			finish = 1;
		if (is_dead == 2)
			return ;
		ft_putstr(ORANGE);
		ft_putnbr(get_time() - philo->table->start);
		write(1, "\t", 1);
		ft_putstr(color);
		ft_putnbr(philo->pos + 1);
		write(1, " ", 1);
		write(1, "[", 1);
		ft_putnbr(philo->eat_count + 1);
		write(1, "]", 1);
		write(1, " ", 1);
		ft_putstr(msg);
		ft_putstr(RESET);
		if (is_dead)
			return ;
	}
	pthread_mutex_unlock(&philo->table->write_m);
}

void	destroy_forks(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->num_philo)
		pthread_mutex_destroy(&table->forks_m[i]);
}

int	destroy_table(t_table *table)
{
	int	i;

	i = -1;
	if (table->error_type == 1)
		return (0);
	else if (table->error_type == 2)
		free(table->philos);
	else if (table->error_type == 3)
		free(table->forks_m);
	else if (table->error_type == 4)
		destroy_forks(table);
	else if (table->error_type == 5)
		pthread_mutex_destroy(&table->write_m);
	else if (table->error_type == 6)
		pthread_mutex_destroy(&table->end_m);
	table->error_type--;
	destroy_table(table);
	return (0);
}

uint64_t	get_time(void)
{
	struct timeval		time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	sign = 1;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	if (str[i])
		return (0);
	return (res * sign);
}
