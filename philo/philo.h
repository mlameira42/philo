/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:47:09 by mlameira          #+#    #+#             */
/*   Updated: 2025/05/09 17:00:31 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H_
# define PHILO_H_

#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct  s_philo
{
    int                 id;
    long long int       times_eaten;
    long long int       n_meals;
    long long int       meals_toeat;
    long long int       time_toeat;
    long long int       time_tosleep;
    long long int       time_todie;
    long long int       philo_amt;
    long long int       time_tothink;
    long long int       last_meal;
    long long int       time;
    pthread_t           thread;
    int                 *is_dead;
    pthread_mutex_t     *l_fork;
    pthread_mutex_t     *r_fork;
    pthread_mutex_t     *death;
}                       t_philo;

int     ft_strlen(char *s);
long long	ft_atoi_lld(const char *nptr);
void    ft_free(t_philo *a, void *b, void  *c);
void    mutexes_init(t_philo *philo, pthread_mutex_t *forks, pthread_mutex_t *death);
void    eat(t_philo *philo);
long    get_abs_time();
void    print_mutex(t_philo *philo, char *str);
int     isdead(t_philo *philo);
void    threads_init(t_philo *philo);
void    philo_sleep(t_philo *philo);
void    waiting(t_philo   *philo, size_t time);
void    think(t_philo   *philo);

#endif 