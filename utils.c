/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:32:47 by bfaisy            #+#    #+#             */
/*   Updated: 2024/04/16 18:18:21 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_char(char c, int fd)
{
	write (fd, &c, 1);
}

void	put_string(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		put_char(s[i], fd);
		i++;
	}
}

int	digit_check(char *c)
{
	while (c && *c)
	{
		if (*c < '0' || *c > '9')
			return (0);
		c++;
	}
	return (1);
}

int	is_int(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (result > 2147483647)
			return (-1);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (1);
}

int	atoi_philo(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}
