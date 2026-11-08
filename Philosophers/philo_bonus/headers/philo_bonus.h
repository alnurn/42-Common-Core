/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:56:28 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:56:36 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# define ERROR "<number_of_philosophers>: 1-250\n<time_to_die>: 1-100000\n<time_to_eat>: 1-100000\n<time_to_sleep>: 1-100000\n\
[number_of_times_each_philosopher_must_eat]: 0-99999\n"
# define SIM_ERROR "simulation failed...\n"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define TAKEFORK "has taken a fork"
# define EAT "is eating"
# define DIED "died"
# define MAX_VALUE 100000
# define MAX_PHILO 250
# define SEM_PRINT "/print"
# define SEM_FORKS "/forks"
# define SEM_DEAD "/dead"
# define SEM_FOOD  "/food"

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_philo
{
	pthread_t	monitor;
	int			id;
	int			eating;
	int			eaten;
	time_t		lasteat;
	char		food_name[10];
	sem_t		*sem_food;
	int			dead;
}				t_philo;

typedef struct s_table
{
	pthread_t	killer;
	int			philonum;
	time_t		dietime;
	time_t		eatime;
	time_t		sleeptime;
	int			numeat;
	pid_t		*pids;
	time_t		start;
	sem_t		*sem_dead;
	sem_t		*sem_print;
	sem_t		*sem_forks;
	t_philo		*philo;
}				t_table;

/*parsearg.c*/
int		parsearg(int argc, char	**argv, t_table	*table);

/*print_utils_bonus.c*/
void	print_error(int errorcode);
void	printmessage(t_table	*table, const char	*str);
void	printdeath(t_table	*table, const char	*str);

/*sim_bonus.c*/
int		sim(t_table	*table);

/*semaphores_bonus.c*/
int		open_global_sems(t_table	*table);
void	close_global_sems(t_table	*table);
int		open_local_sems(t_table	*table);
void	close_local_sems(t_table	*table);

/*time_utils_bonus.c*/
time_t	get_current_time(void);
void	ft_usleep(time_t	milliseconds);
void	waitstart(t_table	*table);

/*exit_utils_bonus.c*/
void	kill_all(t_table	*table);
void	exit_child0(t_table	*table);
void	exit_child1(t_table	*table);

/*init_philo_bonus.c*/
void	philo(t_table	*table, int index);

/*philo_routine_utils_bonus.c*/
void	eat(t_table	*table);
void	think(t_table	*table);
void	dream(t_table	*table);

/*monitor_bonus.c*/
void	*monitor_routine(void	*data);
void	*killer_routine(void	*data);

#endif