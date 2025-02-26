/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:18:08 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/26 19:21:29 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

// void sigint_handler(int handler)
// {
// 	if (handler == SIGINT)
// 		printf("\nIntercepted SIGNIT!\n");
// }

// void set_signal_action(void)
// {
// 	struct sigaction act;

// 	bzero(&act, sizeof(act));
// 	act.sa_handler = &sigint_handler;
// 	sigaction(SIGINT, &act, NULL);
// }

void ft_put_bit(char c, pid_t pid)
{
	int i;

	i = 7;
	while(i >= 0)
	{
		if(((c >> i) & 1) == 0)
		{
			printf("0");
			kill(pid, SIGUSR1);
		}
		if(((c >> i) & 1) == 1)
		{
			printf("1");
			kill(pid, SIGUSR2);
		}
		usleep(2000);
		i--;
	}
	printf("\n");
}

void ft_put_str(char *str, pid_t pid)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_put_bit(str[i], pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	if(ac != 3)
		ft_error();
	pid_t pid;

	pid = ft_atoi(av[1]);
	if(pid <= 0)
		ft_error();
	ft_put_str(av[2], pid);
}