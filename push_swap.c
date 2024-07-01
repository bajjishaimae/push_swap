/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:23:00 by cbajji            #+#    #+#             */
/*   Updated: 2024/06/29 18:03:52 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse(char **av, int ac, t_node **stack_a)
{
	char	**splited;
	char	*joined_args;

	joined_args = join_arguments(ac, av);
	if (!joined_args)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	splited = ft_split(joined_args, ' ');
	free(joined_args);
	if (!splited)
	{
		ft_free_str(splited);
		exit(1);
	}
	put_in_stack(stack_a, splited);
	ft_free_str(splited);
}

void	sort(t_node **stack_a, t_node **stack_b)
{
	if (checksorted(stack_a) == 0 && stack_size(*stack_a) == 2)
		swap_stack(stack_a, 'a');
	else if (checksorted(stack_a) == 0 && stack_size(*stack_a) == 3)
		sort_three(stack_a);
	else if (checksorted(stack_a) == 0 && stack_size(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	else if (checksorted(stack_a) == 0)
		push_to_stack_b(stack_a, stack_b, stack_size(*stack_a) / 3,
			stack_size(*stack_a) / 6);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
	{
		return (0);
	}
	parse(av, ac, &stack_a);
	if (stack_size(stack_a) != 1)
	{
		sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
}
