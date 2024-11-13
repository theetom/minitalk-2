/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:29:52 by toferrei          #+#    #+#             */
/*   Updated: 2024/11/13 15:33:53 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_data	g_data_s;

static void	exit_manager(int pid)
{
		ft_putstr_fd(g_data_s.str, 1);
		write(1, "\n", 2);
		ft_printf("Bits Received: %d\n", g_data_s.bit_counter);
		g_data_s.l = 0;
		g_data_s.l_b = 0;
		g_data_s.str_p = 0;
		g_data_s.s_b = 0;
		free(g_data_s.str);
		kill(pid, SIGUSR2);
}

static void	find_length(int signum)
{
	if (signum == SIGUSR1)
		g_data_s.l = g_data_s.l << 1;
	else
		g_data_s.l = g_data_s.l << 1 | 1;
	g_data_s.l_b++;
}

static void	find_char(int signum)
{
	g_data_s.s_b++;
	if (signum == SIGUSR1)
		g_data_s.str[g_data_s.str_p] = g_data_s.str[g_data_s.str_p] << 1;
	else
		g_data_s.str[g_data_s.str_p] = g_data_s.str[g_data_s.str_p] << 1 | 1;
	if (g_data_s.s_b == 8)
	{
		g_data_s.s_b = 0;
		g_data_s.str_p++;
	}
}

void	handler(int signum, siginfo_t *info, void *nada)
{
	(void)nada;
	g_data_s.bit_counter++;
	if (g_data_s.l_b < 32)
		find_length(signum);
	if (g_data_s.l_b >= 33)
		find_char(signum);
	if (g_data_s.l_b == 32)
	{
		g_data_s.l++;
		g_data_s.str = ft_calloc(g_data_s.l, sizeof * g_data_s.str);
		g_data_s.str[g_data_s.l - 1] = '\0';
		g_data_s.l_b++;
	}
	if (g_data_s.str_p >= (g_data_s.l - 1) && g_data_s.l_b > 32)
		exit_manager(info->si_pid);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	g_data_s.l = 0;
	g_data_s.l_b = 0;
	g_data_s.str_p = 0;
	g_data_s.s_b = 0;
	g_data_s.bit_counter = 0;
	ft_printf("getpid	%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
