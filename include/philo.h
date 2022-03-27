#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

typedef struct	s_philo {
	int			philo_len; //철학자 수
	int			time_life; //생존 시간
	int			time_eat; //먹는 시간
	int			time_sleep; //자는 시간
	int			end_flag; //종료 카운트
}				t_philo;

int	ft_atoi(const char *str);

#endif