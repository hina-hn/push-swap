/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:12:13 by YourName          #+#    #+#             */
/*   Updated: 2025/02/22 16:30:02 by YourName         ###   ########.fr       */
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
	int		sign;
	int		i;

	result = 0;
	if (!is_valid_integer(str, &sign))
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		i = 1;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 &&
				-result < INT_MIN))
			return (0);
		i++;
	}
	*out = (int)(sign * result);
	return (1);
}

t_node	*parse_arguments(int argc, char **argv)
{
	t_node	*stack_a;
	int		i;
	int		value;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!argv[i][0] || !safe_atoi(argv[i], &value))
		{
			ft_dprintf(STDERR_FILENO, "Error\n");
			exit(1);
		}
		if (is_duplicate(stack_a, value))
		{
			ft_dprintf(STDERR_FILENO, "Error\n");
			exit(1);
		}
		add_to_stack(&stack_a, value);
		i++;
	}
	return (stack_a);
}
