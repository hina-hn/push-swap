/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:04:03 by YourName          #+#    #+#             */
/*   Updated: 2025/02/12 19:40:36 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack, char stack_name)
{
	printf("Stack %c: ", stack_name);
	if (!stack)
	{
		printf("(empty)\n");
		return ;
	}
	while (stack)
	{
		printf("%d ", stack->nbr);
		stack = stack->next;
	}
	printf("\n");
}

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

/**
 * @brief スタックを解放する関数
 */
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
		// sort_stacks(stack_a, stack_b);
		sort_three(stack_b);
	}
}
/**
 * @brief コマンドライン引数を解析し、スタックを作成
 */
t_node	*parse_arguments(int argc, char **argv)
{
	t_node	*stack_a;
	int		i;
	int		value;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		add_to_stack(&stack_a, value);
		i++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	if (argc < 2)
	{
		printf("Usage: ./push_swap <numbers>\n");
		return (1);
	}
	stack_a = parse_arguments(argc, argv);
	stack_b = NULL;
	printf("Before sorting:\n");
	print_stack(stack_a, 'A');
	sort_numbers(&stack_a, &stack_b, argc - 1);
	printf("After sorting:\n");
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B'); ///
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}