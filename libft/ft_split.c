/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:01:12 by rcaillie          #+#    #+#             */
/*   Updated: 2024/10/11 11:12:41 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(const char *s, char sep)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != sep)
		{
			count++;
			while (s[i] != sep && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	ft_free_all(char **tab, size_t index)
{
	while (index--)
		free(tab[index]);
	free(tab);
}

static char	**ft_fill_tab(const char *s, char c, char **new)
{
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	end = 0;
	while (s[end])
	{
		if (s[end] != c)
		{
			start = end;
			while (s[end] != c && s[end])
				end++;
			new[i] = ft_substr(s, start, end - start);
			if (!new[i++])
			{
				ft_free_all(new, i);
				return (NULL);
			}
		}
		else
			end++;
	}
	new[i] = NULL;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;

	if (!s)
		return (NULL);
	new = (char **)malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	return (ft_fill_tab(s, c, new));
}
