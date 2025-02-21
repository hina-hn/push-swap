/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:04:03 by YourName          #+#    #+#             */
/*   Updated: 2025/02/19 16:00:34 by YourName         ###   ########.fr       */
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
		sort_stacks(stack_a, stack_b);
	}
}

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

// int	safe_atoi(const char *str)
// {
// 	long	result;
// 	int		i;

// 	// 文字列が整数かチェック
// 	if (!is_valid_integer(str))
// 		fprintf(stderr, "Error\n");
// 	// `ft_atoi()` の結果を `long` で受け取る
// 	result = ft_atoi(str);
// 	// `INT_MIN` 〜 `INT_MAX` の範囲外ならエラー
// 	if (result < INT_MIN || result > INT_MAX)
// 		fprintf(stderr, "Error\n");
// 	// `ft_atoi()` の変換結果と元の文字列が一致しているか確認
// 	// `is_valid_integer()` で事前チェック済みなので、単純なチェックでOK
// 	i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
// 	while (str[i])
// 	{
// 		if (str[i] < '0' || str[i] > '9') // 数字以外があればエラー
// 			fprintf(stderr, "Error\n");
// 		i++;
// 	}
// 	return ((int)result);
// }

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
			fprintf(stderr, "Error\n");
		value = ft_atoi(argv[i]);
		if ((value == 0 && argv[i][0] != '0') || value < INT_MIN
			|| value > INT_MAX)
			fprintf(stderr, "Error\n");
		if (is_duplicate(stack_a, value))
			fprintf(stderr, "Error\n");
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
		return (0);
	stack_a = parse_arguments(argc, argv);
	stack_b = NULL;
	sort_numbers(&stack_a, &stack_b, argc - 1);
	// printf("After sorting:\n");
	// print_stack(stack_a, 'A');
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}