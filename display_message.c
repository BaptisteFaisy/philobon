/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:29:10 by bfaisy            #+#    #+#             */
/*   Updated: 2024/04/17 16:42:34 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	error_message(char *message, int print_usage)
{
	put_string(message, STDOUT_FILENO);
	put_string("\n", STDOUT_FILENO);
	if (print_usage == 1)
	{
		printf("Usage: ./philo <number_of_philosophers> <time_to_die> ");
		printf("<time_to_eat> <time_to_sleep>\n");
		printf("[number_of_times_each_philosopher_must_eat]\n");
	}
	return (EXIT_FAILURE);
}

int	error_message_args(t_table *table)
{
	if (table -> philos_num < 1)
		return (error_message(PHILO_NUM, 0));
	if (table -> time_to_die <= 0)
		return (error_message(DEATH_TIME, 0));
	if (table -> time_to_eat <= 0)
		return (error_message(FOOD_TIME, 0));
	if (table -> time_to_sleep <= 0)
		return (error_message(SLEEP_TIME, 0));
	return (0);
}

void	print_info(t_data_philo *philo, char *action)
{
	long int	time;

	pthread_mutex_lock(philo -> write_message);
	time = get_time_now() - *philo -> start_time;
	if (time >= 0 && time <= 2147483647 && alive_check(philo))
	{
		ft_putnbr1((int)time);
		write(1, " Philo: ", 9);
		ft_putnbr1(philo -> philo_id);
		write(1, " ", 1);
		write(1, action, ft_strlen(action));
		write(1, "\n", 1);
	}
	pthread_mutex_unlock(philo -> write_message);
}
