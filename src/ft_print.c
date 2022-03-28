#include "philo.h"

void	ft_print(t_philos *philo, char *msg)
{
	pthread_mutex_lock(&philo->table->write_m);
	ft_putnbr(get_time() - philo->table->start);
	write(1, " ", 1);
	ft_putnbr(philo->pos + 1);
	ft_putstr(msg);
	pthread_mutex_unlock(&philo->table->write_m);
}
