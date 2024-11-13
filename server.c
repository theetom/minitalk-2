/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:29:52 by toferrei          #+#    #+#             */
/*   Updated: 2024/11/12 20:01:56 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

static t_data	data_s;

static void	find_length(int signum)
{
	if (signum == SIGUSR1)
		data_s.l = data_s.l << 1;
	else
		data_s.l = data_s.l << 1 | 1;
	data_s.l_b++;
}

static void	find_char(int signum)
{
	data_s.s_b++;
	if (signum == SIGUSR1)
		data_s.str[data_s.str_p] = data_s.str[data_s.str_p] << 1;
	else
		data_s.str[data_s.str_p] = data_s.str[data_s.str_p] << 1 | 1;
	if (data_s.s_b == 8)
	{
		data_s.s_b = 0;
		data_s.str_p++;
	}
}

void handler(int signum, siginfo_t *info, void *nada)
{
	(void)nada;
	if (data_s.l_b < 32)
		find_length(signum);
	if (data_s.l_b >= 33)
		find_char(signum);
	if (data_s.l_b == 32)
	{
		data_s.l++;
		data_s.str = calloc(data_s.l, sizeof * data_s.str);
		data_s.str[data_s.l - 1] = '\0';
		data_s.l_b++;
	}
	if (data_s.str_p >= (data_s.l - 1) && data_s.l_b > 32)
	{
		ft_putstr_fd(data_s.str, 1);
		write(1, "\n", 2);
		data_s.l = 0;
		data_s.l_b = 0;
		data_s.str_p = 0;
		data_s.s_b = 0;
		free(data_s.str);
		kill(info->si_pid, SIGUSR2);
	}
	kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;

	data_s.l = 0;
	data_s.l_b = 0;
	data_s.str_p = 0;
	data_s.s_b = 0;
	printf("length is :%d\n", data_s.l);
    printf("getpid	%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{	
		pause();
	}
	return 0;
}



