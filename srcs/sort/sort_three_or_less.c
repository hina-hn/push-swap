/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_or_less.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:12:04 by YourName          #+#    #+#             */
/*   Updated: 2025/02/12 19:21:28 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	if (!stack || !(*stack) || !((*stack)->next) || !(*stack)->next->next)
		return ;
	first = (*stack)->nbr;
	second = (*stack)->next->nbr;
	third = (*stack)->next->next->nbr;
	if (first > second && second > third)
	{
		rotate(stack, "ra");
		swap(stack, "sa");
	}
	else if (first > third && third > second)
		rotate(stack, "ra");
	else if (second > first && first > third)
		reverse_rotate(stack, "rra");
	else if (second > third && third > first)
	{
		swap(stack, "sa");
		rotate(stack, "ra");
	}
	else if (third > first && first > second)
		swap(stack, "sa");
}

void	sort_two(t_node **stack)
{
	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	if ((*stack)->nbr > (*stack)->next->nbr)
	{
		swap(stack, "sa");
	}
}
