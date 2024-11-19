/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:58:06 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/12 10:29:40 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_list	*g_data = NULL;

void	handle_sigint(int sig)
{
	(void)sig;
	ft_lstclear(&g_data, free);
	ft_putstr_fd("\033[0;31m\nServer terminated\033[0m\n", STDOUT_FILENO);
	exit(0);
}

void	process_received_bit(int signum, t_data *data)
{
	if (signum == SIGUSR2)
		data->c |= 0 << data->i;
	else
		data->c |= 1 << data->i;
	data->i++;
}

void	handle_complete_byte(t_data *data)
{
	char	*message;

	if (data->c == '\0')
	{
		kill(data->client_pid, SIGUSR2);
		message = ft_lst_to_str(g_data);
		if (message)
		{
			ft_putstr_fd(message, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
			free(message);
			ft_putstr_fd("\033[0;32mReceived ", STDOUT_FILENO);
			ft_putnbr_fd(ft_lstsize(g_data), STDOUT_FILENO);
			ft_putstr_fd(" characters\033[0m\n", STDOUT_FILENO);
		}
		ft_lstclear(&g_data, free);
	}
	else
	{
		ft_lstadd_back(&g_data, ft_lstnew(ft_strdup_char(data->c)));
	}
	data->c = 0;
	data->i = 0;
}

void	server_handler(int signum, siginfo_t *info, void *context)
{
	static t_data	data;

	(void)context;
	if (data.i == 0)
		reset_data(&data, info);
	process_received_bit(signum, &data);
	if (data.i == 8)
	{
		handle_complete_byte(&data);
		kill(data.client_pid, SIGUSR1);
	}
	else
		kill(data.client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &server_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	signal(SIGINT, handle_sigint);
	ft_putstr_fd("\033[0;31mServer [PID = ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("]\033[0m\n", STDOUT_FILENO);
	while (1)
		pause();
	ft_lstclear(&g_data, free);
	return (0);
}
