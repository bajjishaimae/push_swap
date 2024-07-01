/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:59:50 by cbajji            #+#    #+#             */
/*   Updated: 2024/06/27 11:59:50 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_blank(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	get_last_index(t_node **stack)
{
	t_node	*current;

	current = (*stack);
	while (current->next)
	{
		current = current->next;
	}
	return (current->index);
}

int	checksorted(t_node **stacka)
{
	t_node	*curr;

	curr = *stacka;
	while (curr->next)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	check_above_line(t_node **stack, int value)
{
	int		i;
	t_node	*current;

	i = 0;
	current = *stack;
	while (current)
	{
		if (current->index == value)
			return (i);
		current = current->next;
		i++;
	}
	return (i);
}

t_node	*last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}
