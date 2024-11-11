/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:29:52 by toferrei          #+#    #+#             */
/*   Updated: 2024/11/11 18:31:46 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

t_data	data_s;

void handler(int signum, siginfo_t *info, void *nada)
{

	nada = 0;
	if (data_s.l_b < 32)
		find_length(signum);
	if ()

	
	
	kill(info->si_pid, SIGUSR1);
}

void	find_length(int signum)
{
	if (signum == SIGUSR1)
	{
		data_s.l = data_s.l >> 1;
	}
	if (signum == SIGUSR2)
	{
		write(1, "1", 1);
	}
}
int main(void)
{
	struct sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;

	data_s.l = 0;
    printf("getpid	%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{	
		pause();
	}
	return 0;
}



