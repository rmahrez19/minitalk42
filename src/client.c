/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:18:08 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/27 19:11:33 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

static volatile sig_atomic_t	g_received = 0;

void	sigint_handler(int signal)
{
	if (signal == SIGUSR1)
		g_received = 1;
	else if (signal == SIGUSR2)
		exit(0);
}

void	ft_put_bit(char c, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 0)
		{
			kill(pid, SIGUSR1);
		}
		if (((c >> i) & 1) == 1)
		{
			kill(pid, SIGUSR2);
		}
		g_received = 0;
		while (!g_received)
		{
			usleep(50);
		}
		i--;
	}
}

void	ft_put_str(char *str, pid_t pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_put_bit(str[i], pid);
			i++;
	}
	ft_put_bit(0, pid);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_printf(RED "ERROR NUMBER ARGUMENT" RESET);
		exit(0);
	}
	signal(SIGUSR1, sigint_handler);
	signal(SIGUSR2, sigint_handler);
	ft_printf(YELLOW "%d", getpid());
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		ft_error();
	ft_put_str(av[2], pid);
}
