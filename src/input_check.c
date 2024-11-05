/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:51:47 by ariling           #+#    #+#             */
/*   Updated: 2024/11/05 20:51:49 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_numeric_argument(char *av)
{
	int	i;

	i = 0;
	if (is_sign_char(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_numeric_char(av[i]))
		i++;
	if (av[i] != '\0' && !is_numeric_char(av[i]))
		return (0);
	return (1);
}

static int	contains_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && compare_numeric_strings(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_zero_argument(char *av)
{
	int	i;

	i = 0;
	if (is_sign_char(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	is_valid_input_set(char **av)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!is_numeric_argument(av[i]))
			return (0);
		nb_zeros += is_zero_argument(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (contains_duplicates(av))
		return (0);
	return (1);
}
