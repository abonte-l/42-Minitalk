/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:57:33 by abonte-l          #+#    #+#             */
/*   Updated: 2022/01/05 15:45:52 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	sending_bits(char c, int pid)
{
	int	i;

	i = 128;
	while (i >= 1)
	{
		if (i & c)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr(ERROR_SIGNAL);
				exit(EXIT_FAILURE);
			}	
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr(ERROR_SIGNAL);
				exit(EXIT_FAILURE);
			}
		}
		i /= 2;
		usleep(1000);
	}
}

int	send_str(int pid, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		sending_bits(s[i], pid);
		i++;
	}
	return (0);
}

void	talk_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	(void)signum;
	return ;
}

int	checker_arg_pid(char *str, int ac)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr(ERROR_ARG_CLI);
		exit(EXIT_FAILURE);
	}
	check_pid_nb(str);
	pid = ft_atoi(str);
	if (!(pid <= 0))
		return (ERROR);
	ft_putstr(ERROR_PID);
	exit(EXIT_FAILURE);
	return (pid);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;

	pid = checker_arg_pid(av[1], ac);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);
	sigaddset(&sa.sa_mask, SIGQUIT);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = talk_handler;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_putstr(ERROR_SIGAC_CLI);
	send_str(pid, av[2]);
	return (0);
}
