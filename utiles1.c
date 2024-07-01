/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:45:58 by cbajji            #+#    #+#             */
/*   Updated: 2024/06/27 13:02:55 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lst_new(int *content)
{
	t_node	*head;

	head = malloc(sizeof(t_node));
	if (!head)
		return (NULL);
	head->content = *content;
	head->index = 0;
	head->next = NULL;
	return (head);
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_error(t_node **stack)
{
	t_node	*current;
	t_node	*next_node;

	if (stack != NULL && *stack != NULL)
	{
		current = *stack;
		while (current != NULL)
		{
			next_node = current->next;
			free(current);
			current = next_node;
		}
		*stack = NULL;
	}
	ft_putstr("Error\n");
	exit(1);
}

long long	ft_atoi(char *str, t_node **stack)
{
	int				i;
	long long		n;
	int				s;

	i = 0;
	n = 0;
	s = 1;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			s = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		ft_error(stack);
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			ft_error(stack);
		n = (str[i] - 48) + (n * 10);
		if ((n > 2147483647 && s) || (n > 2147483648 && s == -1))
			ft_error(stack);
		i++;
	}
	return (n * s);
}

char	*ft_join_free(char *save, char *buffer)
{
	char	*temp;

	if (save == NULL)
	{
		save = strdup("");
	}
	temp = ft_strjoin(save, buffer);
	free(save);
	return (temp);
}
