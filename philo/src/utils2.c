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

void	msleep(uint64_t ms)
{
	uint64_t	begin;
	uint64_t	end;

	begin = get_time();
	end = begin;
	while (end - begin < ms)
	{
		usleep(10);
		end = get_time();
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
		write(1, "(null)", 6);
	while (str[++i])
		write(1, &str[i], 1);
}

void	ft_putnbr(uint64_t n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}
