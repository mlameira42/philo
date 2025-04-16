/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:04:06 by mlameira          #+#    #+#             */
/*   Updated: 2025/04/16 15:36:04 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void       free_philo(t_philo *philo)
{
    int i;

    i = -1;
    while(++i < philo->philo_amt)
        pthread_join(philo[i].thread, NULL);
    while(--i >= 0)
        pthread_mutex_destroy(philo[i].l_fork);
    if (philo->death)
        pthread_mutex_destroy(philo->death);
    free(philo->is_dead);
    free(philo);
}

void ft_free(t_philo *a, void *b, void  *c)
{
    if (a)
        free_philo(a);
    if (b)
        free(b);
    if (c)
        free(c);
}