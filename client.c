/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:39:33 by toferrei          #+#    #+#             */
/*   Updated: 2024/11/08 19:03:55 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	*chars_to_binary(int len, char *str)
{
	int	n;
	int m;
	int i;
	int *bin;
	
	bin = malloc(sizeof * bin * len * 8);

	n = 0;
	m = 0;
	while (str[n])
	{
		i = 7;
		while(i >= 0)
		{
			bin[m] = (str[n] >> i) & 1;
			m++;
			i--;
		}
		n++;
	}
	return (bin);
}

void handler(int signum, siginfo_t *info, void *nada)
{
	nada = 0;
	info = 0;
	if (signum == SIGUSR1)
		write(1, "g", 1);
	if (signum == SIGUSR2)
		write(1, "b", 1);
	// kill(info->si_pid, 10);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	int					n;
	struct sigaction	sa;
	int					*bin;
	int					len;


	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;


	if (argc != 3)
		return (0);
	len = ft_strlen(argv[2]);
	bin = chars_to_binary(len, argv[2]);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = atoi(argv[1]);
	
	n = 0;
	while (n < len)
	{
		if (bin[n] = 0)
			write(1, &bin[n], 10);
		if (bin[n] == 0)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		n++;
		sleep(50000);
	}
/* 	while(1)
	{
		pause();
	} */
	// while (n < 6)
	// {
	// 	n++;
	// }
	
	
	
}