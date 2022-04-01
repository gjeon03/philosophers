/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:02:42 by gjeon             #+#    #+#             */
/*   Updated: 2022/03/30 14:02:54 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define ORANGE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

typedef struct s_table	t_table;

typedef struct s_philo {
	pthread_t		thread_id;
	int				philo_id;
	int				num_philos;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				num_of_eat;
	int				eat_counter;
	uint64_t		last_eat;
	t_table			*table;
}					t_philo;

struct s_table {
	uint64_t		start_time;
	t_philo			*philo;
	pthread_mutex_t	*msg;
	pthread_mutex_t	*forks;
};

//thread
void		*make_actions(void *arg);
void		*eat_count(void *arg);

//utils
uint64_t	get_time(void);
void		ft_sleep(uint64_t ms);
void		destroy_mutexes(pthread_mutex_t *forks, \
			pthread_mutex_t *msg, int num_philos);
int			check_death(t_philo *philo, int num_philos);
int			ft_atoi(const char *str);
int			check_argv(t_philo *philo);

//init
int			init_data(t_philo *philo, char **argv, int argc);
void		init_forks(pthread_mutex_t *forks, int num_philos);
void		create_threads(t_philo *philo, int num_philos);
int			init_philo(t_table *table, char **argv, int argc, int num_philos);

//actions
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
void		take_fork(t_philo *philo);
void		dead(t_philo *philo);

#endif
