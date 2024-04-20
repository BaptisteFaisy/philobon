/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:32:33 by bfaisy            #+#    #+#             */
/*   Updated: 2024/04/17 15:58:38 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// printf est pas protege contre le multithreading 
#ifndef PHILO_H
# define PHILO_H

/* libraries */
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

/* actions	*/
# define EAT			("is eating ")
# define SLEEP			("is sleeping")
# define THINK			("is thinking")
# define TAKE_L_FORK	("has taken left fork")
# define TAKE_R_FORK	("has taken right fork")
# define FINISH_MEAL	("philosophers finished eating")
# define DIE			("died")

/* arguments errors */
# define ARGS_NUM		("Wrong number of arguments, try 5 or 6")
# define PHILO_NUM		("There has to be at least 1 philosopher")
# define ONLY_DIGIT		("Arguments have to be represented as digits")
# define SIZE_MATTERS	("Arguments have to be greater than 0")
# define DEATH_TIME		("The time_to_die has to be greater than 0")
# define FOOD_TIME		("The time_to_eat has to be greater than 0")
# define SLEEP_TIME		("The time_to_sleep has to be greater than 0")

/* structures */
typedef struct s_data_philo
{
	int				philo_id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_x_times;
	int				ate_x_times;
	int				*already_ate_max;
	long int		last_meal_time;
	long int		*start_time;
	int				stop;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*main_lock;
	pthread_mutex_t	*priv_lock;
	pthread_mutex_t	*write_message;
}				t_data_philo;

typedef struct s_table
{
	int				philos_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_x_times;
	int				already_ate_max;
	pthread_t		*threads;
	t_data_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_message;
	long int		start_time;
	pthread_mutex_t	main_lock;
	pthread_mutex_t	*priv_lock;
}				t_table;

/* arguments check */
int				set_check_args(t_table *table, int argc, char **argv);
void			set_arguments(t_table *table, int argc, char **argv);

/* control */
int				meal_control(t_table *table, t_data_philo *philo);
void			control(t_table *table, t_data_philo *philo);

/* destroy mutexes and free */
void			destroy(t_table *table);
void			free_all(t_table *table);

/* display message */
int				error_message(char *message, int print_usage);
int				error_message_args(t_table *table);
void			print_info(t_data_philo *philo, char *action);
int				ft_putnbr1(int nb);

/* initialize */
int				init_all(t_table *table);
void			init_philo(t_table *table, t_data_philo *philo);
int				init_mutex(t_table *table);
int				init_threads(t_table *table);

/* routine */
void			*philo_routine(void *arg);
void			update_meal_status(t_data_philo *philo);
int				meal(t_data_philo	*philo);
int				alive_check(t_data_philo *philo);

/* time */
long int		get_time_now(void);
void			new_sleep(int mil_sec);
int				wait_threads(t_table *table);

/* utils */
void			put_char(char c, int fd);
void			put_string(char *s, int fd);
int				digit_check(char *c);
int				is_int(char *str);
int				atoi_philo(char *str);

#endif