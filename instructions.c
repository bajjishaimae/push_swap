/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:18:56 by cbajji            #+#    #+#             */
/*   Updated: 2024/05/26 15:37:54 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_node **node, char c)
{
	t_node	*tmp;

	if (!(*node) || !((*node)->next))
		return ;
	tmp = (*node)->next;
	(*node)->next = tmp->next;
	tmp->next = *node;
	(*node) = tmp;
	if (c == 'a')
		ft_putstr("sa\n");
	else if (c == 'b')
		ft_putstr("sb\n");
}

void	push_to(t_node **dest, t_node **src, char c)
{
	t_node	*tmp;

	if (!(*src))
		return ;
	tmp = (*src);
	(*src) = (*src)->next;
	tmp->next = (*dest);
	(*dest) = tmp;
	if (c == 'a')
		ft_putstr("pa\n");
	else if (c == 'b')
		ft_putstr("pb\n");
}

void	rotate_stack(t_node **node, char c)
{
	t_node	*tmp;

	if (!(*node) || !((*node)->next))
		return ;
	tmp = (*node);
	(*node) = (*node)->next;
	last_node(tmp)->next = tmp;
	tmp->next = NULL;
	if (c == 'a')
		ft_putstr("ra\n");
	else if (c == 'b')
		ft_putstr("rb\n");
}

void	reverse_rotate_stack(t_node **node, char c)
{
	t_node	*tmp;

	if (!(*node) || !((*node)->next))
		return ;
	tmp = (*node);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = (*node);
	(*node) = tmp->next;
	tmp->next = NULL;
	if (c == 'a')
		ft_putstr("rra\n");
	else if (c == 'b')
		ft_putstr("rrb\n");
}
