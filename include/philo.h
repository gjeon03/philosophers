#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

typedef struct			s_philos
{
	int					is_eating;
	int					fork_left;
	int					fork_right;
	int					eat_count;
	int					pos;
	t_table				*table;
	unsigned long long	last_eat;
}						t_philos;

typedef struct			s_table {
	int					num_philo; //철학자 수
	int					time_life; //생존 시간
	int					time_eat; //먹는 시간
	int					time_sleep; //자는 시간
	int					eat_count; //종료 카운트
	int					is_dead;
	t_philos			*philos;
	pthread_mutex_t		*forks_m;
	pthread_mutex_t		write_m;
	pthread_mutex_t		end_m;
	unsigned long long	start;
}						t_table;

int	ft_atoi(const char *str);

#endif