/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:55:12 by YourName          #+#    #+#             */
/*   Updated: 2025/02/21 16:02:18 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node **stack, char *operation)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_printf("%s\n", operation);
}

void	silent_reverse_rotate(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrr(t_node **a, t_node **b)
{
	silent_reverse_rotate(a);
	silent_reverse_rotate(b);
	ft_printf("rrr\n");
}
