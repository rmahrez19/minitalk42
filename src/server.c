/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:39:35 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/26 19:52:25 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <strings.h>
#include "../libft/libft.h"

void sigint_handler(int signal)
{
    static char c = 0;
    static int bit = 0;

    if (signal == SIGUSR1)
    {
		c = c << 1;;
	}
    else if (signal == SIGUSR2)
    {
		c = (c << 1) | 1;
    }
	if(bit < 7)
    	bit++;
    else
    {
        write(1, &c, 1);
        c = 0;
        bit = 0;
    }
}

//
void	set_signal_action(void)
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
	// char tab[9];
	int i;

	pid = getpid();
	ft_putnbr_fd(pid, 0);
	write(1, "\n", 1);
	i = 0;
	set_signal_action();
	while(1)
	{
		pause();
		// print_char(tab, &i);
		// printf("%d", sig);
	}
}


// int main(void)
// {
// 	printf("%d", ft_atoi_base("11001", "01"));
// }