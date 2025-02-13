/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:50:47 by YourName          #+#    #+#             */
/*   Updated: 2025/02/13 21:19:40 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;
	t_node	*current;

	// t_node	*new_b_top;
	if (!a || !(*a))
		return ;
	cheapest_node = NULL;
	current = *a;
	while (current)
	{
		if (current->is_cheapest)
		{
			printf("in");
			cheapest_node = current;
			break ;
		}
		current = current->next;
	}
	if (!cheapest_node)
		return ;
	// 🔹 A, B を同時に回転・逆回転
	if (cheapest_node->best_direction == UP_UP)
		while (*a != cheapest_node && *b != cheapest_node->target_node)
			rr(a, b);
	else if (cheapest_node->best_direction == DOWN_DOWN)
		while (*a != cheapest_node && *b != cheapest_node->target_node)
			rrr(a, b);
	// 🔹 `cheapest_node` を A の `top` に持ってくる
	while (*a != cheapest_node)
	{
		if (cheapest_node->best_direction == UP_DOWN
			|| cheapest_node->best_direction == UP_UP)
			rotate(a, "ra");
		else
			reverse_rotate(a, "rra");
	}
	// 🔹 `cheapest_node->target_node` を B の `top` に持ってくる
	while (*b != cheapest_node->target_node)
	{
		if (cheapest_node->best_direction == DOWN_UP
			|| cheapest_node->best_direction == UP_UP)
			rotate(b, "rb");
		else
			reverse_rotate(b, "rrb");
	}
	// 🔹 A の `top` を B にプッシュ
	push(b, a, "pb");
	// while (*a != cheapest_node)
	// {
	// 	if (cheapest_node->best_direction == UP_UP)
	// 		rr(a, b);
	// 	else if (cheapest_node->best_direction == DOWN_DOWN)
	// 		rrr(a, b);
	// 	else if (cheapest_node->best_direction == UP_DOWN)
	// 	{
	// 		rotate(a, "ra");
	// 		reverse_rotate(b, "rrb");
	// 	}
	// 	else if (cheapest_node->best_direction == DOWN_UP)
	// 	{
	// 		reverse_rotate(a, "rra");
	// 		rotate(b, "rb");
	// 	}
	// }
	// push(b, a, "pb");
	// new_b_top = *b;
	// while (*b != new_b_top->target_node)
	// {
	// 	if (new_b_top->target_node->index <= stack_len(*b) / 2)
	// 		rotate(b, "rb");
	// 	else
	// 		reverse_rotate(b, "rrb");
	// }
}

void	move_b_to_a(t_node **a, t_node **b)
{
	t_node	*target_node;

	if (!b || !(*b))
		return ;
	target_node = (*b)->target_node;
	if (!target_node)
		return ;
	if (!is_target_in_a(*a, target_node))
		return ;
	while (*a != target_node)
	{
		if (target_node->index <= stack_len(*a) / 2)
			rotate(a, "ra");
		else
			reverse_rotate(a, "rra");
	}
	push(a, b, "pa");
}

int	is_target_in_a(t_node *a, t_node *target_node)
{
	while (a)
	{
		if (a == target_node)
			return (1);
		a = a->next;
	}
	return (0);
}
