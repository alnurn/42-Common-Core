/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:56:28 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:56:36 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define LLMAX_DIGITS 19

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		t;
	long long		eaten;
	long long		lasteat;
	int				eating;
	pthread_mutex_t	food;
	pthread_mutex_t	fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}					t_philo;

typedef struct s_data
{
	int				dead;
	pthread_mutex_t	death;
	pthread_mutex_t	message;
	long long		philonum;
	long long		dietime;
	long long		eatime;
	long long		sleeptime;
	long long		numeat;
	long long		start;
	pthread_t		track;
	t_philo			*philos;
}					t_data;

/*routine.c*/
void				*routine(void	*arg);

/*eat_utils.c*/
void				onephilo(t_philo	*philo);
void				lockforks(t_philo	*philo);
void				unlockforks(t_philo	*philo);

/*track.c*/
void				*track(void	*arg);

/*mutexes.c*/
void				mutexinit(t_data	*data);
void				mutexdestroy(t_data	*data);

/*pthreads.c*/
void				pthreadjoin(t_data	*data);
void				pthreadcreate(t_data	*data);

/*parsearg.c*/
int					parsearg(int argc, char	**argv, t_data	*data);

/*atoull.c*/
unsigned long long	atoull(char	*nptr);

/*sim.c*/
void				sim(t_data	*data);

/*philo_utils.c*/
long long			get_current_time(void);
int					ft_usleep(t_data	*data, long long milliseconds);
void				printmessage(t_data	*data, int id, const char	*str);
int					checkdeath(t_data	*data);

#endif
