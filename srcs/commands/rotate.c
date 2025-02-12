/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:49:36 by YourName          #+#    #+#             */
/*   Updated: 2025/02/12 18:54:47 by YourName         ###   ########.fr       */
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
	printf("%s\n", operation);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a, "ra");
	rotate(b, "rb");
	printf("rr\n");
}