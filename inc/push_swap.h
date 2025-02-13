/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:03:26 by YourName          #+#    #+#             */
/*   Updated: 2025/02/13 21:20:27 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_h
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*next;
	struct s_node	*target_node;
	int				is_cheapest;
	int				push_cost;
	int				best_direction;
}					t_node;

enum				e_direction
{
	UP_UP,
	DOWN_DOWN,
	UP_DOWN,
	DOWN_UP
};

t_node				*parse_arguments(int argc, char **argv);
void				sort_numbers(t_node **stack_a, t_node **stack_b, int size);
void				free_stack(t_node **stack);
void				add_to_stack(t_node **stack, int value);
void				print_stack(t_node *stack, char stack_name);

void				push(t_node **dest, t_node **src, char *operation);
void				reverse_rotate(t_node **stack, char *operation);
void				rrr(t_node **a, t_node **b);
void				rotate(t_node **stack, char *operation);
void				rr(t_node **a, t_node **b);
void				swap(t_node **stack, char *operation);
void				ss(t_node **a, t_node **b);

void				sort_three(t_node **stack);
void				sort_two(t_node **stack);

void				min_node_on_top(t_node **top);
void				sort_stacks(t_node **a, t_node **b);
int					stack_len(t_node *stack);
int					is_sorted(t_node *stack);

void				calc_push_cost(t_node *a, int len_a, int len_b);
void				calc_all_push_costs(t_node *a, t_node *b);
int					ft_min(int a, int b);
int					ft_max(int a, int b);

int					calc_cost_up_up(t_node *a);
int					calc_cost_down_down(t_node *a, int len_a, int len_b);
int					calc_cost_up_down(t_node *a, int len_b);
int					calc_cost_down_up(t_node *a, int len_a);

void				find_target_a(t_node *a, t_node *b);
void				find_target_b(t_node *a, t_node *b);
void				set_index_both_stack(t_node *a, t_node *b);
void				set_index_stack(t_node *top);
void				mark_cheapest_node(t_node *top);

void				move_a_to_b(t_node **a, t_node **b);
void				move_b_to_a(t_node **a, t_node **b);

t_node				*find_min_node(t_node *stack);
t_node				*find_max_node(t_node *stack);

int					is_target_in_a(t_node *a, t_node *target_node);

#endif
