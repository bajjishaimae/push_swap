/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:35:36 by cbajji            #+#    #+#             */
/*   Updated: 2024/06/28 15:46:08 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_arguments(int ac, char **av)
{
	int		i;
	char	*joined_args;
	char	*temp;

	i = 1;
	joined_args = NULL;
	while (i < ac)
	{
		if (strcmp(av[i], "") == 0 || ft_blank(av[i]))
		{
			ft_putstr("Error\n");
			exit(1);
		}
		temp = ft_join_free(joined_args, av[i]);
		joined_args = ft_join_free(temp, " ");
		i++;
	}
	return (joined_args);
}

void	check_duplic(t_node **stack)
{
	t_node	*current;
	t_node	*compare;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	while (current != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			if (current->content == compare->content)
			{
				ft_error(stack);
			}
			compare = compare->next;
		}
		current = current->next;
	}
}

void	put_in_stack(t_node **stack, char **str)
{
	int		i;
	int		nbr;
	t_node	*head;

	i = 0;
	while (str[i])
	{
		nbr = ft_atoi(str[i], stack);
		head = ft_lst_new(&nbr);
		ft_lstadd_back(stack, head);
		i++;
	}
	check_duplic(stack);
	give_index(stack);
}

void	give_index(t_node **head)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	if (!*head || !head)
		return ;
	current = *head;
	while (current != NULL)
	{
		index = 0;
		compare = *head;
		while (compare != NULL)
		{
			if (current->content > compare->content)
			{
				index++;
			}
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
