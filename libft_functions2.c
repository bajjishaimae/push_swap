/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:09:35 by cbajji            #+#    #+#             */
/*   Updated: 2024/06/21 17:09:35 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_wordcounter(char *str, char c)
{
	int	i;
	int	nword;

	i = 0;
	nword = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
		{
			nword++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (nword);
}

static int	ft_word_len(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	*ft_free(char **arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
	return (NULL);
}

static char	**ft_fillptr(char *in, char **out, char c, int words)
{
	int		i;
	int		wlen;
	int		j;

	i = 0;
	wlen = 0;
	while (i < words)
	{
		while (*in == c)
			in++;
		wlen = ft_word_len(in, c);
		out[i] = (char *)malloc((wlen * sizeof(char)) + 1);
		if (!out[i])
			return (ft_free(out, i));
		j = 0;
		while (j < wlen)
			out[i][j++] = *in++;
		out[i][j] = '\0';
		i++;
	}
	out[i] = NULL;
	return (out);
}

char	**ft_split(char *s, char c)
{
	int		words;
	char	**ptr;

	if (!s)
		return (NULL);
	words = ft_wordcounter(s, c);
	ptr = (char **)malloc((words + 1) * sizeof(char *));
	if (!(ptr))
		return (NULL);
	ptr = ft_fillptr(s, ptr, c, words);
	return (ptr);
}
