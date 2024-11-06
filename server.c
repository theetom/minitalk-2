/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:29:52 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/30 14:02:37 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

void handler(int signum)
{
	if (signum == SIGUSR1)
		printf("0");
	if (signum == SIGUSR2)
		printf("1");
}

int main(void)
{
    printf("getpid%d\n", getpid());
		signal(SIGUSR1, &handler);
		signal(SIGUSR2, &handler);
	while (1)
	{	
		// sleep(1);
		pause();
		}
	return 0;
}



