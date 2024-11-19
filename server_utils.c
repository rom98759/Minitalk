/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:59:42 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/13 08:40:27 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strdup_char(char c)
{
	char	*dup;

	dup = malloc(2 * sizeof(char));
	if (!dup)
		return (NULL);
	dup[0] = c;
	dup[1] = '\0';
	return (dup);
}

char	*ft_lst_to_str(t_list *lst)
{
	char	*str;
	char	*tmp;
	char	*new_str;
	size_t	len;

	len = 0;
	str = ft_calloc(1, sizeof(char));
	if (!str)
		return (NULL);
	while (lst)
	{
		tmp = (char *)lst->content;
		new_str = ft_strjoin(str, tmp);
		free(str);
		str = new_str;
		if (!str)
			return (NULL);
		len += ft_strlen(tmp);
		lst = lst->next;
	}
	return (str);
}

void	reset_data(t_data *data, siginfo_t *info)
{
	data->client_pid = info->si_pid;
	data->c = 0;
	data->i = 0;
}
