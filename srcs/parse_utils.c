/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:52:23 by YourName          #+#    #+#             */
/*   Updated: 2025/02/23 12:52:48 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->nbr == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_valid_integer(const char *str, int *sign)
{
	int	i;

	*sign = 1;
	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (!str[i + 1])
			return (0);
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	safe_atoi(const char *str, int *out)
{
	long	result;
	int		s;
	int		i;

	result = 0;
	if (!is_valid_integer(str, &s))
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		i = 1;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if ((s == 1 && result > INT_MAX) || (s == -1 && (-result) < INT_MIN))
			return (0);
		i++;
	}
	*out = (int)(s * result);
	return (1);
}
