/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:39:33 by toferrei          #+#    #+#             */
/*   Updated: 2024/11/12 20:01:22 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signum, siginfo_t *info, void *nada)
{
	(void)nada;
	(void)info;
	if (signum == SIGUSR2)
	{
		write(1, "MEssage received \n", 19);
		exit(0);
	}
}

static void	send_bits(char c, int pid)
{
	int	n;

	n = 7;
	while (n >= 0)
	{
		if ((c >> n) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		n--;
		usleep(50000);
	}
}

static void	send_length(int i, int pid)
{
	int	n;

	n = 31;
	while (n >= 0)
	{
		if ((i >> n) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		n--;
		usleep(50000);
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	int					n;
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		if (kill(pid, 0) || pid < 0)
			return (1);
		send_length(ft_strlen(argv[2]), pid);
		n = 0;
		while (argv[2][n])
		{
			send_bits(argv[2][n], pid);
			n++;
		}
		while (1)
			pause();
	}
}