/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:32:38 by bfaisy            #+#    #+#             */
/*   Updated: 2024/04/16 18:18:16 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_data_philo	*philo;

	philo = (t_data_philo *)arg;
	if (philo -> philo_id % 2 == 0)
		new_sleep(philo -> time_to_eat * 0.9);
	while (alive_check(philo))
	{
		if (meal(philo) == -1)
			return (NULL);
		if (!alive_check(philo))
			return (NULL);
		print_info(philo, SLEEP);
		new_sleep(philo -> time_to_sleep);
		print_info(philo, THINK);
	}
	return (NULL);
}

void	update_meal_status(t_data_philo *philo)
{
	pthread_mutex_lock(philo -> priv_lock);
	philo -> last_meal_time = get_time_now();
	pthread_mutex_unlock(philo -> priv_lock);
	if (philo -> eat_x_times != 0)
	{
		if (++philo -> ate_x_times == philo -> eat_x_times)
		{
			pthread_mutex_lock(philo -> main_lock);
			*philo -> already_ate_max += 1;
			pthread_mutex_unlock(philo -> main_lock);
		}
	}
}

int	meal(t_data_philo	*philo)
{
	int	i;

	if (!alive_check(philo))
		return (-1);
	i = pthread_mutex_lock(philo -> left_fork);
	print_info(philo, TAKE_L_FORK);
	if (!alive_check(philo))
		return (pthread_mutex_unlock(philo -> left_fork), -1);
	if (philo -> right_fork == NULL)
		return (pthread_mutex_unlock(philo -> left_fork),
			new_sleep(philo -> time_to_die * 1), -1);
	if (i != -1)
		pthread_mutex_unlock(philo -> left_fork);
	pthread_mutex_lock(philo -> right_fork);
	print_info(philo, TAKE_R_FORK);
	print_info(philo, EAT);
	if (!alive_check(philo))
		return (pthread_mutex_unlock(philo -> right_fork), -1);
	update_meal_status(philo);
	if (!alive_check(philo))
		return (pthread_mutex_unlock(philo -> right_fork), -1);
	new_sleep(philo -> time_to_eat);
	return (pthread_mutex_unlock(philo -> right_fork), 0);
}

int	alive_check(t_data_philo *philo)
{
	pthread_mutex_lock(philo -> main_lock);
	if (!philo -> stop)
	{
		pthread_mutex_unlock(philo -> main_lock);
		return (1);
	}
	pthread_mutex_unlock(philo -> main_lock);
	return (0);
}
