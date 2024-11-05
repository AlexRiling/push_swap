/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:53:03 by ariling           #+#    #+#             */
/*   Updated: 2024/11/05 20:53:05 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;


t_stack		*initialize_stack(int ac, char **av);
void		assign_value_indices(t_stack *stack_a, int ac);


int			is_sorted(t_stack *stack);
void		sort_small_stack(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);


int			find_lowest_index_position(t_stack **stack);
void		assign_target_positions(t_stack **stack_a, t_stack **stack_b);


void		calculate_move_costs(t_stack **stack_a, t_stack **stack_b);
void		execute_optimal_move(t_stack **stack_a, t_stack **stack_b);


void		execute_move(t_stack **a, t_stack **b, int cost_a, int cost_b);


void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);


t_stack		*find_stack_tail(t_stack *stack);
t_stack		*find_second_last_node(t_stack *stack);
t_stack		*create_new_node(int value);
void		append_to_stack(t_stack **stack, t_stack *new);
int			calculate_stack_size(t_stack	*stack);


void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			nb_abs(int nb);

void		exit_error(t_stack **stack_a, t_stack **stack_b);


int			is_valid_input_set(char **av);
int			is_numeric_char(char c);
int			is_sign_char(char c);
int			compare_numeric_strings(const char *s1, const char *s2);

#endif
