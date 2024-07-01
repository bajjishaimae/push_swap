/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:08:56 by cbajji            #+#    #+#             */
/*   Updated: 2024/06/28 15:47:22 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node_stack
{
	int					content;
	int					index;
	struct s_node_stack	*next;
}	t_node;

//parsing
char		*join_arguments(int ac, char **av);
void		check_duplic(t_node **stack);
void		put_in_stack(t_node **stack, char **str);
void		give_index(t_node **head);
//libft_functions
t_node		*ft_lstlast(t_node *lst);
void		ft_lstadd_back(t_node **lst, t_node *new);
char		**ft_split(char *s, char c);
int			ft_isdigit(char c);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
//utiles
t_node		*ft_lst_new(int *content);
void		ft_free_str(char **str);
void		ft_error(t_node **stack);
long long	ft_atoi(char *str, t_node **stack);
char		*ft_join_free(char *save, char *buffer);
int			ft_blank(char *str);
void		free_stack(t_node **stack);
//instructions
void		push_to(t_node **dest, t_node **src, char c);
void		swap_stack(t_node **stack, char c);
void		rotate_stack(t_node **stack, char c);
void		reverse_rotate_stack(t_node **stack, char c);
//sorting
void		sort_three(t_node **stack);
int			get_last_index(t_node **stack);
void		push_to_stack_b(t_node **stack_a, t_node **stack_b, int p1, int p2);
int			stack_size(t_node *stack);
int			checksorted(t_node **stacka);
int			check_above_line(t_node **stack, int value);
t_node		*last_node(t_node *node);
int			getspot(t_node **stack, int index);
void		sort_five(t_node **stack, t_node **stackb);
void		ft_putstr(char *s);