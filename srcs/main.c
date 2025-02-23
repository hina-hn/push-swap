/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:04:03 by YourName          #+#    #+#             */
/*   Updated: 2025/02/23 13:07:47 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_stack(t_node **stack, int value)
{
	t_node	*new;
	t_node	*tmp;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		exit(1);
	new->nbr = value;
	new->next = NULL;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	sort_numbers(t_node **stack_a, t_node **stack_b, int size)
{
	if (size == 1)
	{
	}
	else if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else
	{
		sort_stacks(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	stack_a = parse_arguments(argc, argv);
	stack_b = NULL;
	stack_size = stack_len(stack_a);
	sort_numbers(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

// void	print_stack(t_node *stack, char stack_name)
// {
// 	ft_printf("Stack %c: ", stack_name);
// 	if (!stack)
// 	{
// 		ft_printf("(empty)\n");
// 		return ;
// 	}
// 	while (stack)
// 	{
// 		ft_printf("%d ", stack->nbr);
// 		stack = stack->next;
// 	}
// 	ft_printf("\n");
// }

// print_stack(stack_a, 'A');