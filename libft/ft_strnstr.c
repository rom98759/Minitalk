/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:02:58 by rcaillie          #+#    #+#             */
/*   Updated: 2024/10/14 13:27:34 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	j = 0;
	i = 0;
	len = ft_strlen(s2);
	if (len == 0)
		return ((char *)s1);
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s1[i + j] && s1[i + j] == s2[j] && i + j < n)
			j++;
		if (j == len)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
