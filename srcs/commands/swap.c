/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:04:22 by YourName          #+#    #+#             */
/*   Updated: 2025/02/12 19:07:51 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack, char *operation)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	printf("%s\n", operation);
}

void	ss(t_node **a, t_node **b)
{
	swap(a, "sa");
	swap(b, "sb");
	printf("ss\n");
}
