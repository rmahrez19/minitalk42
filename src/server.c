/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:39:35 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/27 20:15:21 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"
#include <signal.h>

void	ft_put_message(char c)
{
	static char	*msg = NULL;
	char		*temp;
	char		c_2[2];

	c_2[0] = c;
	c_2[1] = '\0';
	if (msg == NULL)
		msg = ft_strdup(c_2);
	else
	{
		temp = ft_strjoin(msg, c_2);
		free(msg);
		msg = temp;
	}
	if (c == '\0')
	{
		ft_printf(MAGENTA "message👉 :");
		ft_printf(GREEN "%s\n" RESET, msg);
		free(msg);
		msg = NULL;
	}
}

void	sigint_handler(int signal, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = 0;

	(void)context;
	if (signal == SIGUSR1)
	{
		c = c << 1;
	}
	else if (signal == SIGUSR2)
	{
		c = (c << 1) | 1;
	}
	if (bit < 7)
		bit++;
	else
	{
		ft_put_message(c);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	set_signal_action(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_sigaction = &sigint_handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

int	main(void)
{
	pid_t	pid;
	int		i;

	pid = getpid();
	ft_printf(YELLOW "PID du SERVER 👉: " BLUE);
	ft_printf("%d" RESET, pid);
	write(1, "\n", 1);
	i = 0;
	set_signal_action();
	while (1)
		pause();
}
