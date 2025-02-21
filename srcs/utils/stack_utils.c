/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:10:08 by YourName          #+#    #+#             */
/*   Updated: 2025/02/14 10:18:44 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target_node;
	long	closest_smaller_value;

	while (a)
	{
		closest_smaller_value = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr
				&& current_b->nbr > closest_smaller_value)
			{
				closest_smaller_value = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_smaller_value == LONG_MIN)
			a->target_node = find_max_node(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	find_target_b(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target_node;
	long	closest_larger_value;

	while (b)
	{
		closest_larger_value = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr
				&& current_a->nbr < closest_larger_value)
			{
				closest_larger_value = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_larger_value == LONG_MAX)
			b->target_node = find_min_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_index_both_stack(t_node *a, t_node *b)
{
	set_index_stack(a);
	set_index_stack(b);
}

void	set_index_stack(t_node *top)
{
	int		i;
	t_node	*current;

	if (!top)
		return ;
	current = top;
	i = 0;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

void	mark_cheapest_node(t_node *top)
{
	long	cheapest_cost;
	t_node	*cheapest_node;
	t_node	*current;

	if (!top)
		return ;
	current = top;
	while (current)
	{
		current->is_cheapest = 0;
		current = current->next;
	}
	cheapest_cost = LONG_MAX;
	cheapest_node = NULL;
	current = top;
	while (current)
	{
		if (current->push_cost < cheapest_cost)
		{
			cheapest_cost = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	if (cheapest_node)
		cheapest_node->is_cheapest = 1;
}
