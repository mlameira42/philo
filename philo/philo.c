/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:42:05 by mlameira          #+#    #+#             */
/*   Updated: 2025/04/16 15:49:40 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    philo_sleep(t_philo *philo)
{
    /*pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
    if (isdead(philo))
        return;
    print_mutex(philo, "is sleeping");
    waiting(philo, philo->time_tosleep);*/
    pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	if (isdead(philo))
		return ;
	print_mutex(philo, "is sleeping");
	waiting(philo, philo->time_tosleep);
}
void    eat(t_philo *philo)
{
    if (isdead(philo))
        return;
    if (philo->id % 2)
        pthread_mutex_lock(philo->r_fork);
    else
        pthread_mutex_lock(philo->l_fork);
    print_mutex(philo, "has taken a fork");
    if (philo->id % 2)
        pthread_mutex_lock(philo->l_fork);
    else
        pthread_mutex_lock(philo->r_fork);
    if (isdead(philo))
        return;
    print_mutex(philo, "has taken a fork");
    philo->n_meals++;
    print_mutex(philo, "is eating");
    waiting(philo, philo->time_toeat);
    pthread_mutex_lock(philo->death);
    philo->last_meal = get_abs_time();
    pthread_mutex_unlock(philo->death);
}
void    think(t_philo   *philo)
{
    if(isdead(philo))
        return;
    print_mutex(philo, "is thinking");
}