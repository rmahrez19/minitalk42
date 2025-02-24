/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:39:35 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/24 22:15:50 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <strings.h>
#include "../libft/libft.h"

static volatile int sig = -1;

void sigint_handler(int handler)
{
	if (handler == SIGUSR1)
		sig = 0;
	else if (handler == SIGUSR2)
		sig = 1;
}
//
void set_signal_action(void)
{
	struct sigaction act;

	ft_bzero(&act, sizeof(act));
	act.sa_handler = &sigint_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);

	// if(sig != 0)

}

int main(void)
{
	pid_t pid;
	char tab[7];
	int i;
	char c = 0;

	pid = getpid();
	ft_putnbr_fd(pid, 0);
	write(1, "\n", 1);
	i = 0;
	while(1)
	{
		set_signal_action();
		if(sig != -1)
		{

			if(sig == 0)
			{
				// write(1, "0", 1);
				tab[i] = '0';
			}
			if(sig == 1)
			{
				// write(1, "1", 1);
				tab[i] = '1';
			}
			sig = -1;
			i++;
		}
		if(i == 8)
		{
			c = ft_atoi_base(tab, "01");
			write(1, &c, 1);
			i = 0;
		}
		pause();
		// printf("%d", sig);
	}
}
