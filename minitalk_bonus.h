/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:46:45 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/12 10:50:06 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

# define PID_MAX 4194304
# ifndef SLEEP_TIME
#  define SLEEP_TIME 100
# endif

typedef struct s_data
{
	char	c;
	int		i;
	int		client_pid;
}	t_data;

// PROTOTYPES FOR SERVER
void	server_handler(int signum, siginfo_t *info, void *context);
void	handle_sigint(int sig);
void	process_received_bit(int signum, t_data *data);
void	handle_complete_byte(t_data *data);

// PROTOTYPES FOR SERVER_UTILS
char	*ft_lst_to_str(t_list *lst);
void	reset_data(t_data *data, siginfo_t *info);
char	*ft_strdup_char(char c);

// PROTOTYPES FOR CLIENT
void	send_bit(int pid, int bit);
void	send_char(int pid, char c);
void	send_message(int pid, char *msg);

#endif
