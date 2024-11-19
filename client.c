/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:58:08 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/04 11:58:08 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_received = 0;

static void	handle_sig(int signum)
{
	if (signum == SIGUSR1)
	{
		g_received = 1;
	}
	else if (signum == SIGUSR2)
	{
		g_received = 1;
		ft_putstr_fd("\033[0;34mServer received all the bits\033[0m\n",
			STDOUT_FILENO);
	}
}

void	send_char(int pid, char c)
{
	int	i;
	int	bit;

	bit = 0;
	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		send_bit(pid, bit);
		i++;
	}
}

void	send_message(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_char(pid, msg[i]);
		i++;
	}
	send_char(pid, '\0');
}

void	send_bit(int pid, int bit)
{
	int	wait_time;

	wait_time = 0;
	if (bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	while (g_received == 0 && wait_time < 1000000)
	{
		usleep(SLEEP_TIME);
		wait_time += SLEEP_TIME;
	}
	if (wait_time >= 1000000 || g_received == 0)
	{
		ft_putstr_fd("\033[0;31mError: Server did not receive the bit\033[0m\n",
			STDERR_FILENO);
		exit(1);
	}
	g_received = 0;
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr_fd("Usage: ./client [PID] [Message]\n", 2);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0 || pid > PID_MAX || kill(pid, 0) == -1)
	{
		ft_putstr_fd("Invalid PID\n", STDERR_FILENO);
		return (1);
	}
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	ft_putstr_fd("\033[0;32mSending ", STDOUT_FILENO);
	ft_putnbr_fd(ft_strlen(av[2]), STDOUT_FILENO);
	ft_putstr_fd(" characters\033[0m\n", STDOUT_FILENO);
	send_message(pid, av[2]);
	return (0);
}
