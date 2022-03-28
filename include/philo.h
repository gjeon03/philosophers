#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_table	t_table;

typedef struct			s_philos
{
	int					is_eating;
	int					pos;
	int					fork_left;
	int					fork_right;
	int					eat_count;
	t_table				*table;
	pthread_mutex_t		eat_m;
	int					last_eat;
}						t_philos;

struct					s_table {
	int					num_philo; //철학자 수
	int					time_die; //생존 시간
	int					time_eat; //먹는 시간
	int					time_sleep; //자는 시간
	int					eat_count; //종료 카운트
	int					is_dead;
	unsigned long long	start;
	t_philos			*philos;
	pthread_mutex_t		*forks_m;
	pthread_mutex_t		write_m;
	pthread_mutex_t		dead_m;
};

//utils
int	ft_atoi(char *str);
unsigned long long	get_time(void);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);

//print
void	ft_print(t_philos *philo, char *msg);

//init
void	init_threads(t_table *table);
void	init_mutex(t_table *table);
void	init_philos(t_table *table);
int		init(int argc, char *argv[], t_table *table);

//actions
void	*make_actions(void *philo_v);

//error
void	ft_error(char *str, t_table *table);

#endif