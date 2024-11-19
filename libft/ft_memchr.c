/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:56:01 by rcaillie          #+#    #+#             */
/*   Updated: 2024/10/10 09:46:03 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *m, int c, size_t size)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *) m;
	while (i < size)
	{
		if (s[i] == (unsigned char)c)
			return ((void *)m + i);
		i++;
	}
	return (NULL);
}
