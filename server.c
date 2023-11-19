/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsakar <emsakar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:07:48 by emsakar           #+#    #+#             */
/*   Updated: 2023/09/16 19:11:10 by emsakar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static int	g_i = 128;

void	signal_process(int sig)
{
	static char	c;

	if (sig == SIGUSR1)
		c += g_i;
	g_i /= 2;
	if (g_i == 0)
	{
		write(1, &c, 1);
		c = 0;
		g_i = 128;
	}
}

void	print(int nb)
{
	if (nb > 9)
		print(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}

int	main(void)
{
	int	id;

	write(1, "Server started with PID==>\n", 27);
	id = getpid();
	print(id);
	signal(SIGUSR1, signal_process);
	signal(SIGUSR2, signal_process);
	while (1)
	{
		pause();
	}
	return (0);
}
