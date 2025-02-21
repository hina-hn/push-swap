/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:10:08 by YourName          #+#    #+#             */
/*   Updated: 2025/02/21 16:59:44 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	reset_cheapest_flag(t_node *top)
{
	t_node	*current;

	current = top;
	while (current)
	{
		current->is_cheapest = 0;
		current = current->next;
	}
}

void	mark_cheapest_node(t_node *top)
{
	long	cheapest_cost;
	t_node	*cheapest_node;
	t_node	*current;

	cheapest_cost = LONG_MAX;
	cheapest_node = NULL;
	if (!top)
		return ;
	reset_cheapest_flag(top);
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
