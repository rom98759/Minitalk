/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 07:51:54 by rcaillie          #+#    #+#             */
/*   Updated: 2024/10/11 08:36:23 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementcount, size_t elementsize)
{
	void	*ptr;

	if (elementcount == 0 || elementsize == 0)
	{
		elementcount = 0;
		elementsize = 0;
	}
	if (elementcount != 0 && elementsize > 65535 / elementcount)
		return (NULL);
	ptr = malloc(elementcount * elementsize);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, elementcount * elementsize);
	return (ptr);
}
