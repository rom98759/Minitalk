/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:31:14 by rcaillie          #+#    #+#             */
/*   Updated: 2024/10/11 08:29:13 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_start(char *s, char *set)
{
	int	i;

	i = 0;
	while (s[i] && ft_strchr(set, s[i]))
		i++;
	return (i);
}

static int	ft_count_end(char *s, char *set)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0 && ft_strchr(set, s[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimmed_str;
	int		len;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = ft_count_start((char *)s1, (char *)set);
	end = ft_count_end((char *)s1, (char *)set);
	if (start > end)
		return (ft_strdup(""));
	len = end - start + 1;
	trimmed_str = (char *)malloc(len + 1);
	if (!trimmed_str)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		trimmed_str[i++] = s1[start++];
	}
	trimmed_str[i] = '\0';
	return (trimmed_str);
}
