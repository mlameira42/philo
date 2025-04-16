/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:46:56 by mlameira          #+#    #+#             */
/*   Updated: 2025/04/16 15:48:09 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int  philo_init(t_philo *philo, char **argv)
{
    long long int   i;
    int             *death;

    death = malloc(sizeof(int));
    if (!death)
        return 1;
    i = -1;
    *death = 0;
    while(++i < ft_atoi_lld(argv[1]))
    {
        philo[i].philo_amt = ft_atoi_lld(argv[1]);
        philo[i].time_todie = ft_atoi_lld(argv[2]);
        philo[i].time_toeat = ft_atoi_lld(argv[3]);
        philo[i].time_tosleep = ft_atoi_lld(argv[4]);
        if (argv[5] && ft_atoi_lld(argv[5]) >= 0)
            philo[i].meals_toeat = ft_atoi_lld(argv[5]);
        else
            philo[i].meals_toeat = -1; //depois ve se mudas isto de modo a n ter tantas cenas
        philo[i].id = i;
        philo[i].last_meal = get_abs_time();
        philo[i].time = get_abs_time();
        philo[i].n_meals = 0;
        philo[i].is_dead = death;
    }
    return 0;
}
int main(int argc, char **argv)
{
    t_philo         *philo;
    pthread_mutex_t *forks;
    pthread_mutex_t *death;
    
    if (argc < 5 || argc > 6)
        return printf("the program must take from 4 to 5 arguments max but has %d\n", argc - 1);
    philo = malloc(sizeof(t_philo) * ft_atoi_lld(argv[1]));
    forks = malloc(sizeof(pthread_mutex_t) * ft_atoi_lld(argv[1]));
    death = malloc(sizeof(pthread_mutex_t));
    if (!philo || !forks || !death)
        return ft_free(philo, forks, death), 1;
    if (philo_init(philo, argv))
        return ft_free(philo, forks, death), 1;
    mutexes_init(philo, forks, death);
    threads_init(philo);
    ft_free(philo, forks, death);
    return 1;
}
