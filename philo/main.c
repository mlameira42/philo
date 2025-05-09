/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:46:56 by mlameira          #+#    #+#             */
/*   Updated: 2025/05/09 18:02:01 by mlameira         ###   ########.fr       */
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

int ft_parse(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc < 5 || argc > 6)
        return (printf("the program must take from 4 to 5 arguments max but has %d\n", argc - 1), 0);
    while (++i < argc)
        if (ft_atoi_lld(argv[i]) < 0)
            return (printf("invalid arguments, negative numbers\n"), 0);
    if (!ft_atoi_lld(argv[1]))
        return printf("No philosopher in sight!\n"), 0;
    return 1;
}
int main(int argc, char **argv)
{
    t_philo         *philo;
    pthread_mutex_t *forks;
    pthread_mutex_t *death_flg;
    
    if (!ft_parse(argc, argv))
        return EXIT_FAILURE;
    philo = malloc(sizeof(t_philo) * ft_atoi_lld(argv[1]));
    forks = malloc(sizeof(pthread_mutex_t) * ft_atoi_lld(argv[1]));
    death_flg = malloc(sizeof(pthread_mutex_t));
    if (!philo || !forks || !death_flg)
        return ft_free(philo, forks, death_flg), 1;
    if (philo_init(philo, argv))
        return ft_free(philo, forks, death_flg), 1;
    mutexes_init(philo, forks, death_flg);
    threads_init(philo);
    ft_free(philo, forks, death_flg);
    return 0;
}
