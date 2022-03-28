#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

typedef struct	s_philos
{
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_m;
	int 	start_eat;
	int		pos;
	int		fork_left;
	int		fork_right;
	int		eat_count;
	t_data *data;
}				t_philos;

typedef struct			s_table {
	int					num_philo; //철학자 수
	int					time_life; //생존 시간
	int					time_eat; //먹는 시간
	int					time_sleep; //자는 시간
	int					eat_count; //종료 카운트
	int					is_dead;
	t_philos			*philos;
}						t_table;

//utiles
int	ft_atoi(const char *str);

//init
void	init_mutex(t_table *table);
void	init_philos(t_table *table);
void	init(t_table *table);

#endif