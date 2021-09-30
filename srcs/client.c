/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:35:09 by aloubar           #+#    #+#             */
/*   Updated: 2021/09/30 16:24:02 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_sig;

static	void	ft_signal(void)
{
	while (g_sig == 0)
		usleep(100);
	if (g_sig == 1)
		g_sig = 0;
}

static int	ft_send_signal(int pid, int sigusr)
{
	if (sigusr == 0)
	{
		if (kill(pid, SIGUSR1) != 0)
		{
			ft_putendl_fd("SIRGUSR1 Signal failed! Please try again.", 2);
			return (0);
		}
		ft_signal();
	}
	if (sigusr == 1)
	{
		if (kill(pid, SIGUSR2) != 0)
		{
			ft_putendl_fd("SIGUSR2 Signal failed! Please try again.", 2);
			return (0);
		}
		ft_signal();
	}
	return (1);
}

static int	ft_choose_signal(char *str, int pid)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (++j < 8)
		{
			usleep(300);
			if (128 >> j & str[i])
			{
				if (!(ft_send_signal(pid, 1)))
					return (0);
			}
			else
				if (!(ft_send_signal(pid, 0)))
					return (0);
		}
	}
	i = -1;
	while (++i < 8)
		if (!(ft_send_signal(pid, 0)))
			return (0);
	return (1);
}

void	ft_handler(int sig)
{
	(void)sig;
	g_sig = 1;
	return ;
}

int	main(int ac, char **av)
{
	int	pid_of_server;

	pid_of_server = 0;
	if (ac != 3)
	{
		ft_putendl_fd("Args should be PID then a String! Please try again.", 2);
		exit(0);
	}
	else if (ac == 3)
	{
		signal(SIGUSR1, ft_handler);
		ft_check_errors(av);
		pid_of_server = ft_atoi(av[1]);
		if (pid_of_server < 1 || pid_of_server > 4194304)
		{
			ft_putendl_fd("PID number is not valid! Please try again.", 2);
			exit(0);
		}
		if (!(ft_choose_signal(av[2], pid_of_server)))
			exit(0);
	}
	return (0);
}
