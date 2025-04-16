/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:50:18 by mlameira          #+#    #+#             */
/*   Updated: 2025/04/16 15:45:24 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen(char *s)
{
    int i;
    
    i = -1;
    while (s && s[++i])
        ;
    return i;
}

long long int	ft_atoi_lld(const char *nptr)
{
	int	i;
	long long int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] < 14 && nptr[i] > 8))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			sign *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result *= 10;
		result += (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}

void    print_mutex(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->death);
	if (!(*philo->is_dead))
	{
		printf("%lld %d %s\n", (get_abs_time() - philo->time), philo->id + 1, str);
        if (str[0] == 'd')
            *philo->is_dead = 1;
    }
    pthread_mutex_unlock(philo->death);
    isdead(philo);
}

int     isdead(t_philo *philo)
{
    if (philo->n_meals == philo->meals_toeat)
        return (1);
    pthread_mutex_lock(philo->death);
    if (*philo->is_dead)
        return (pthread_mutex_unlock(philo->death), 1);
    pthread_mutex_unlock(philo->death);
    if (get_abs_time() - philo->last_meal > philo->time_todie)
        return (print_mutex(philo, "died"), 1);
    return 0;
}
void    waiting(t_philo   *philo, size_t time)
{
    size_t i;

    i = get_abs_time();
    while (get_abs_time() - i < time)
    {
        if (isdead(philo))
            break;
        usleep(1);
    }
}