/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:00:06 by rcaillie          #+#    #+#             */
/*   Updated: 2024/10/10 09:11:45 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	unsigned char	*c_dest;
	unsigned char	*c_src;
	size_t			i;

	c_dest = (unsigned char *)destination;
	c_src = (unsigned char *)source;
	if (c_dest == c_src)
		return (destination);
	if (c_dest > c_src && c_src + size > c_dest)
	{
		while (size--)
			c_dest[size] = c_src[size];
	}
	else
	{
		i = 0;
		while (i < size)
		{
			c_dest[i] = c_src[i];
			i++;
		}
	}
	return (destination);
}
