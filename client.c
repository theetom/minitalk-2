/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:39:33 by toferrei          #+#    #+#             */
/*   Updated: 2024/11/07 02:25:13 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	chars_to_binary(int *bin)
{

}

int	main(int argc, char **argv)
{
	char	test[6] = {'0', '1', '0', '1', '0', '1'};
	pid_t	pid;
	int		n;
	int		*bin;

	if (argc != 2)
		return (0);
	pid = atoi(argv[1]);
	printf("%d", pid);
	
	n = chars_to_binary();
	if (test[n] == '0')
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	// while (n < 6)
	// {
	// 	n++;
	// }
	
	
	
}