/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:40:35 by aloubar           #+#    #+#             */
/*   Updated: 2021/09/30 16:25:17 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_isdigitminitalk(char *str)
{
	while (*str)
		if (!(ft_isdigit(*str++)))
			return (0);
	return (1);
}

void	ft_check_errors(char **av)
{
	if (!av[2])
	{
		ft_putendl_fd("String is not valid. Please try again.", 2);
		exit(0);
	}
	if (!(ft_isdigitminitalk(av[1])))
	{
		ft_putendl_fd("1st Arg should be the PID. Please try again.", 2);
		exit(0);
	}
}
