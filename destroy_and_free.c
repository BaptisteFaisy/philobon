/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:28:57 by bfaisy            #+#    #+#             */
/*   Updated: 2024/04/16 18:17:59 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table -> philos_num)
	{
		pthread_mutex_destroy(&table -> forks[i]);
		pthread_mutex_destroy(&table -> priv_lock[i]);
	}
	pthread_mutex_destroy(&table -> main_lock);
	pthread_mutex_destroy(&table -> write_message);
}

void	free_all(t_table *table)
{
	if (table -> threads)
		free(table -> threads);
	if (table -> forks)
		free(table -> forks);
	if (table -> philos)
		free(table -> philos);
	if (table -> priv_lock)
		free(table -> priv_lock);
	if (table)
		free(table);
}
