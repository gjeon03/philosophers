#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_table	t_table;

typedef struct		s_philos
{
	pthread_mutex_t	eat_m;
	int				start_eat;
	int				pos;
	int				fork_left;
	int				fork_right;
	int				eat_count;
	t_table			*table;
}					t_philos;

struct				s_table {
	int				num_philo; //철학자 수
	int				time_die; //생존 시간
	int				time_eat; //먹는 시간
	int				time_sleep; //자는 시간
	int				eat_count; //종료 카운트
	int				is_dead;
	pthread_mutex_t	*forks;
	t_philos		*philos;
};

//utiles
int	ft_atoi(char *str);

//init
void	init_mutex(t_table *table);
void	init_philos(t_table *table);
int	init(int argc, char *argv[], t_table *table);

//error
void	ft_error(char *str, t_table *table);

#endif