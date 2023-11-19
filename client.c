/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsakar <emsakar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:58:24 by emsakar           #+#    #+#             */
/*   Updated: 2023/09/16 19:08:56 by emsakar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	tmp;

	i = 0;
	sign = 1;
	tmp = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		tmp = (tmp * 10) + (str[i] - 48);
		i++;
	}
	return (tmp * sign);
}

static void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, 30);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		write(1, "Error: wrong number of arguments\n", 33);
	else
	{
		pid = ft_atoi(argv[1]);
		if (pid < 0)
		{
			write(1, "PID is negative.", 15);
			return (0);
		}
		i = 0;
		while (argv[2][i])
		{
			send_char(pid, argv[2][i]);
			i++;
		}
	}
}
