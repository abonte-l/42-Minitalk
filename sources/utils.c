/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:59:37 by abonte-l          #+#    #+#             */
/*   Updated: 2022/01/05 15:46:06 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = -nbr;
			ft_putnbr(nbr);
		}
		else if (nbr < 10)
		{
			c = (nbr % 10) + 48;
			write(1, &c, 1);
		}
		else
		{
			ft_putnbr(nbr / 10);
			c = (nbr % 10) + 48;
			write(1, &c, 1);
		}
	}
}

int	ft_atoi(const char *str)
{
	long int	i;
	long int	num;
	long int	neg;

	i = 0;
	num = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

void	check_pid_nb(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' && str[i] > '9')
		{
			ft_putstr(ERROR_PID);
			exit(EXIT_FAILURE);
		}
		else
			i++;
	}
}
