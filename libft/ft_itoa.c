/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:59:26 by rcaillie          #+#    #+#             */
/*   Updated: 2024/10/10 19:47:40 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_nb(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	char	*new;
	int		i;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_count_nb(nb);
	new = (char *)malloc(i + 1);
	if (!new)
		return (NULL);
	new[i--] = '\0';
	if (nb == 0)
		new[0] = '0';
	if (nb < 0)
	{
		new[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		new[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (new);
}
