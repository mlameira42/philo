/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:56:20 by mlameira          #+#    #+#             */
/*   Updated: 2025/04/15 16:16:31 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philo.h"

void    mutexes_init(t_philo *philo, pthread_mutex_t *forks, pthread_mutex_t *death)
{
    int i;

    i = -1;
    while(++i < philo->philo_amt)
    {
        philo[i].l_fork = &forks[i];
        philo[i].r_fork = &forks[(i + 1) % philo->philo_amt];
        pthread_mutex_init(philo[i].l_fork, NULL);
        philo[i].death = death;
    }
    pthread_mutex_init(philo->death, NULL);
}
