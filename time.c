/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:32:42 by bfaisy            #+#    #+#             */
/*   Updated: 2024/04/16 18:18:19 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	new_sleep(int mil_sec)
{
	long int	start_time;

	start_time = get_time_now();
	while ((get_time_now() - start_time) < mil_sec)
		usleep(100);
}

int	wait_threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table -> philos_num)
		pthread_join(table -> threads[i], NULL);
	return (1);
}
