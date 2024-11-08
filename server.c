/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:29:52 by toferrei          #+#    #+#             */
/*   Updated: 2024/11/08 19:01:16 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"


void handler(int signum, siginfo_t *info, void *nada)
{
	nada = 0;
	if (signum == SIGUSR1)
		write(1, "0", 1);
	if (signum == SIGUSR2)
		write(1, "1", 1);
	kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	struct sigaction sa;


	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;

    printf("getpid	%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{	
		pause();
	}
	return 0;
}



