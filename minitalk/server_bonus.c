/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:56:14 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/17 20:56:16 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_printline(t_line	*s)
{
	ft_printf("%s", s->str);
	free(s->str);
	s->str = NULL;
	s->n = 0;
	s->flag = 0;
	s->len = 0;
}

static char	*ft_createstr(size_t len)
{
	char	*str;

	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
	{
		ft_putstr_fd("ERROR\n", STDERR_FILENO);
		return (NULL);
	}
	str[len] = 0;
	return (str);
}

static void	handler2(siginfo_t *info, t_line	*s)
{
	static t_encode	e;

	if (!(e.byte % 8))
	{
		e.bit = 0;
		e.byte = 0;
	}
	if (info->si_signo == SIGUSR2)
		e.bit = e.bit | 1 << e.byte;
	if (e.byte == 7 && (int) e.bit == 4)
	{
		ft_printline(s);
		e.i = 0;
		kill(info->si_pid, SIGUSR1);
	}
	else if (e.byte == 7 && (int) e.bit != 4)
	{
		s->str[e.i] = e.bit;
		e.i++;
		kill(info->si_pid, SIGUSR2);
	}
	else
		kill(info->si_pid, SIGUSR2);
	e.byte++;
}

static void	handler(int signum, siginfo_t *info, void	*ucontext)
{
	static t_line	s;
	static int		num = 1;

	(void) ucontext;
	if (s.n < 32)
	{
		if (signum == SIGUSR2)
			s.len += num;
		num = num * 2;
		s.n++;
		kill(info->si_pid, SIGUSR2);
	}
	else if (!s.flag && s.n >= 32)
	{
		s.str = ft_createstr(s.len);
		if (!s.str)
			exit (EXIT_FAILURE);
		s.flag = 1;
		num = 1;
		kill(info->si_pid, SIGUSR2);
	}
	else
		handler2(info, &s);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID: %i\n", getpid());
	while (1)
		pause ();
	return (EXIT_SUCCESS);
}
