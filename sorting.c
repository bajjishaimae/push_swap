/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:47:52 by cbajji            #+#    #+#             */
/*   Updated: 2024/06/28 15:07:51 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int		i;
	t_node	*current;

	current = stack;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	sort_three(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = *stack;
	second = (*stack)->next;
	third = (*stack)->next->next;
	if (first->index > second->index && first->index > third->index)
	{
		rotate_stack(stack, 'a');
		first = *stack;
		second = (*stack)->next;
		third = (*stack)->next->next;
	}
	if (second->index > third->index)
	{
		reverse_rotate_stack(stack, 'a');
		first = *stack;
		second = (*stack)->next;
		third = (*stack)->next->next;
	}
	if (first->index > second->index)
		swap_stack(stack, 'a');
}

void	sort_five(t_node **stack, t_node **stackb)
{
	int	index;
	int	list_size;

	list_size = stack_size(*stack);
	index = 0;
	while (stack_size(*stack) > 3)
	{
		if (check_above_line(stack, index) > list_size / 2)
		{
			while ((*stack)->index != index)
				reverse_rotate_stack(stack, 'a');
		}
		else
		{
			while ((*stack)->index != index)
				rotate_stack(stack, 'a');
		}
		index++;
		push_to(stackb, stack, 'b');
	}
	sort_three(stack);
	while (*stackb)
		push_to(stack, stackb, 'a');
}

void	push_back_to_a(t_node **stack_a, t_node **stack_b, int biggest)
{
	while (*stack_b || !checksorted(stack_a))
	{
		while ((*stack_b) && (*stack_b)->index != ((*stack_a)->index) - 1)
		{
			if ((*stack_b) && (get_last_index(stack_a) < (*stack_b)->index
					|| get_last_index(stack_a) == biggest))
			{
				push_to(stack_a, stack_b, 'a');
				rotate_stack(stack_a, 'a');
			}
			else if ((*stack_b) && stack_size(*stack_b) && check_above_line(
					stack_b, (*stack_a)->index - 1) <= stack_size(*stack_b) / 2)
				rotate_stack(stack_b, 'b');
			else if ((*stack_b) && stack_size(*stack_b) && check_above_line(
					stack_b, (*stack_a)->index - 1) > stack_size(*stack_b) / 2)
				reverse_rotate_stack(stack_b, 'b');
		}
		while ((*stack_b) && (*stack_b)->index == ((*stack_a)->index) - 1)
			push_to(stack_a, stack_b, 'a');
		while (get_last_index(stack_a) == (*stack_a)->index - 1)
			reverse_rotate_stack(stack_a, 'a');
	}
}

void	push_to_stack_b(t_node **stack_a, t_node **stack_b, int p1, int p2)
{
	int	p0;

	p0 = -1;
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->index < p1)
			push_to(stack_b, stack_a, 'b');
		else
			rotate_stack(stack_a, 'a');
		if (stack_size(*stack_b) > 1 && (*stack_b)->index >= p0
			&& (*stack_b)->index <= p2)
			rotate_stack(stack_b, 'b');
		if (stack_size(*stack_b) == p1)
		{
			p0 = p1;
			p1 += stack_size(*stack_a) / 3;
			p2 = stack_size(*stack_a) / 6 + p0;
		}
	}
	sort_three(stack_a);
	if (stack_size(*stack_b))
		push_back_to_a(stack_a, stack_b, get_last_index(stack_a));
}
