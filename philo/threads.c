/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:38:11 by mlameira          #+#    #+#             */
/*   Updated: 2025/05/17 23:05:06 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static void    *initialize_thread(void *arg)
{
    t_philo   *philo;
    
    philo = (t_philo *)arg;
    if (!(philo->id % 2))
        usleep(500);
    if (philo->philo_amt == 1 && !isdead(philo))
    {
        if (pthread_mutex_lock(philo->l_fork))        
            return NULL;
        while (1)
            if (isdead(philo))
                break;
        pthread_mutex_unlock(philo->l_fork);
    }
    else 
    {   
        while (1)
        {
            if (isdead(philo))
                break;
            eat(philo);
            philo_sleep(philo);
            think(philo);
        }
    }
    return NULL;
}
void    threads_init(t_philo *philo)
{
    long long i;
    
    i = -1;
    while (++i < philo->philo_amt)
        pthread_create(&philo[i].thread, NULL, &initialize_thread, &philo[i]);
    usleep(100);
}