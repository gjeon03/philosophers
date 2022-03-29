#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

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

typedef struct s_philos
{
	int					is_eating;
	int					pos;
	int					fork_left;
	int					fork_right;
	int					eat_count;
	t_table				*table;
	pthread_mutex_t		eat_m;
	pthread_mutex_t		live_m;
	uint64_t			last_eat;
}						t_philos;

struct					s_table {
	int					run_flag;
	int					error_type;
	int					num_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					eat_count;
	int					is_dead;
	uint64_t			start;
	t_philos			*philos;
	pthread_mutex_t		*forks_m;
	pthread_mutex_t		write_m;
	pthread_mutex_t		end_m;
};

//utils
int					ft_atoi(char *str);
uint64_t			get_time(void);
int					destroy_table(t_table *table);
void				ft_print(t_philos *philo, char *msg, \
					int is_dead, char *color);

void				msleep(unsigned long long ms);
void				ft_putstr(char *str);
void				ft_putnbr(unsigned long long n);
int					check_argv(t_table *table);

//init
void				*dead(void *philo_v);
int					init_threads(t_table *table);
int					init(int argc, char *argv[], t_table *table);

//actions
void				*make_actions(void *philo_v);

//error
void				ft_error(char *str, t_table *table);

#endif
