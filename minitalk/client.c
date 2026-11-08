/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:56:14 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/17 20:56:16 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack;

static void	ack_handler(int signum)
{
	g_ack = 1;
	if (signum == SIGUSR2)
		ft_putstr_fd("ACK from server is recieved\n", STDOUT_FILENO);
	if (signum == SIGUSR1)
		ft_putstr_fd("Message is recieved by server\n", STDOUT_FILENO);
}

static void	ft_signal(int signum)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(signum, &sa, NULL);
}

static void	ft_sendchar(char ch, pid_t s_pid)
{
	size_t	n;

	n = 0;
	while (n < 8)
	{
		g_ack = 0;
		if ((ch >> n & 1) == 1)
			kill(s_pid, SIGUSR2);
		else
			kill(s_pid, SIGUSR1);
		while (!g_ack)
			usleep (1);
		n++;
	}
}

static void	ft_sendlen(size_t len, pid_t s_pid)
{
	int	n;

	n = 0;
	while (n < 32)
	{
		g_ack = 0;
		if ((len >> n & 1) == 1)
			kill(s_pid, SIGUSR2);
		else
			kill(s_pid, SIGUSR1);
		while (!g_ack)
			usleep (1);
		n++;
	}
	g_ack = 0;
	kill(s_pid, SIGUSR2);
	while (!g_ack)
		usleep (1);
}

int	main(int argc, char **argv)
{
	pid_t		s_pid;
	size_t		i;
	uint32_t	len;

	if (argc != 3)
	{
		ft_putstr_fd("WRONG NUMBER OF ARGUMENTS\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	s_pid = (pid_t) atoi(argv[1]);
	i = 0;
	ft_signal(SIGUSR1);
	ft_signal(SIGUSR2);
	len = (uint32_t) ft_strlen((const char *) argv[2]);
	ft_sendlen(len, s_pid);
	while (argv[2][i])
	{
		ft_sendchar((unsigned char) argv[2][i], s_pid);
		i++;
	}
	ft_sendchar(4, s_pid);
	return (EXIT_SUCCESS);
}
