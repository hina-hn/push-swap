/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:49:36 by YourName          #+#    #+#             */
/*   Updated: 2025/02/21 16:02:21 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack, char *operation)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	ft_printf("%s\n", operation);
}

void	silent_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rr(t_node **a, t_node **b)
{
	silent_rotate(a);
	silent_rotate(b);
	ft_printf("rr\n");
}
