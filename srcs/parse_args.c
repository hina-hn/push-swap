/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:12:13 by YourName          #+#    #+#             */
/*   Updated: 2025/02/23 13:24:37 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	process_argument(t_node **stack, char *arg)
{
	int	value;

	if (!safe_atoi(arg, &value))
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		exit(1);
	}
	if (is_duplicate(*stack, value))
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		exit(1);
	}
	add_to_stack(stack, value);
}

void	parse_string_argument(t_node **stack, char *arg)
{
	char	**split_args;
	int		j;

	split_args = ft_split(arg, ' ');
	if (!split_args)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		exit(1);
	}
	j = 0;
	while (split_args[j])
	{
		process_argument(stack, split_args[j]);
		j++;
	}
	free_split(split_args);
}

t_node	*parse_arguments(int argc, char **argv)
{
	t_node	*stack_a;
	int		i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			parse_string_argument(&stack_a, argv[i]);
		else
			process_argument(&stack_a, argv[i]);
		i++;
	}
	return (stack_a);
}
