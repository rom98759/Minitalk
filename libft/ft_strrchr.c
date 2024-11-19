/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:54:06 by rcaillie          #+#    #+#             */
/*   Updated: 2024/10/09 18:27:15 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc == '\0')
		return ((char *)s + ft_strlen(s));
	len = ft_strlen(s) - 1;
	while (len >= 0)
	{
		if ((unsigned char)s[len] == uc)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}
