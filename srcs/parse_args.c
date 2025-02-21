/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:12:13 by YourName          #+#    #+#             */
/*   Updated: 2025/02/21 16:13:50 by YourName         ###   ########.fr       */
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

int	is_valid_integer(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
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
		if (!is_valid_integer(argv[i]))
			ft_dprintf(STDERR_FILENO, "Error\n");
		value = ft_atoi(argv[i]);
		if ((value == 0 && argv[i][0] != '0') || value < INT_MIN
			|| value > INT_MAX)
			ft_dprintf(STDERR_FILENO, "Error\n");
		if (is_duplicate(stack_a, value))
			ft_dprintf(STDERR_FILENO, "Error\n");
		add_to_stack(&stack_a, value);
		i++;
	}
	return (stack_a);
}
