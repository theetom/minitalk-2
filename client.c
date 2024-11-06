/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:39:33 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/30 14:01:02 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	char	test[6] = {'0', '1', '0', '1', '0', '1'};
	pid_t	pid;
	if (argc != 2)
		return 0;
	pid = atoi(argv[1]);
	printf("%d", pid);
	int n = 0;
	if (test[n] == '0')
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	// while (n < 6)
	// {
	// 	n++;
	// }
	
	
	
}