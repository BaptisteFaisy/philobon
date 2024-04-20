/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:29:50 by bfaisy            #+#    #+#             */
/*   Updated: 2024/04/16 18:04:26 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc < 5 || argc > 6)
		return (error_message(ARGS_NUM, 1), exit(1), 1);
	table = malloc(sizeof(t_table));
	if (set_check_args(table, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_all(table) == -1)
		return (EXIT_FAILURE);
	control(table, table -> philos);
	wait_threads(table);
	destroy(table);
	free_all(table);
}
