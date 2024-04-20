/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:28:27 by bfaisy            #+#    #+#             */
/*   Updated: 2024/04/17 15:14:56 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_check_args(t_table *table, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!digit_check(argv[i]))
			return (free(table), error_message(ONLY_DIGIT, 0));
		if (is_int(argv[i]) <= 0)
			return (free(table), error_message(SIZE_MATTERS, 0));
		i++;
	}
	set_arguments(table, argc, argv);
	if (error_message_args(table) == EXIT_FAILURE)
		return (free(table), EXIT_FAILURE);
	return (0);
}

void	set_arguments(t_table *table, int argc, char **argv)
{	
	table -> philos_num = atoi_philo(argv[1]);
	table -> time_to_die = atoi_philo(argv[2]);
	table -> time_to_eat = atoi_philo(argv[3]);
	table -> time_to_sleep = atoi_philo(argv[4]);
	if (argc == 6)
	{
		table -> eat_x_times = atoi_philo(argv[5]);
		if (argv[5] && table -> eat_x_times < 0)
			printf("The number of meals cannot be negative\n");
	}
	else
		table -> eat_x_times = 0;
}
