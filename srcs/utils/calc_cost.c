/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:36:45 by YourName          #+#    #+#             */
/*   Updated: 2025/02/12 17:40:53 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_cost_up_up(t_node *a)
{
	return (ft_max(a->index, a->target_node->index));
}

int	calc_cost_down_down(t_node *a, int len_a, int len_b)
{
	return (ft_max(len_a - a->index, len_b - a->target_node->index));
}

int	calc_cost_up_down(t_node *a, int len_b)
{
	return (a->index + (len_b - a->target_node->index));
}

int	calc_cost_down_up(t_node *a, int len_a)
{
	return ((len_a - a->index) + a->target_node->index);
}

