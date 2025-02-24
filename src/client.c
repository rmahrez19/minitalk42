/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:18:08 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/23 19:11:58 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <strings.h>


void sigint_handler(int handler)
{
	if (handler == SIGINT)
		printf("\nIntercepted SIGNIT!\n");
}

void set_signal_action(void)
{
	struct sigaction act;

	bzero(&act, sizeof(act));
	act.sa_handler = &sigint_handler;
	sigaction(SIGINT, &act, NULL);
}

int	main(void)
{
	set_signal_action();
	while(1)
		continue;
}