/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:30:48 by rcaillie          #+#    #+#             */
/*   Updated: 2024/10/09 14:49:42 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size )
{
	unsigned char	*c_dest;
	unsigned char	*c_src;

	c_dest = (unsigned char *) destination;
	c_src = (unsigned char *) source;
	if (!destination && !source)
		return (0);
	while (size--)
		*c_dest++ = *c_src++;
	return (destination);
}
