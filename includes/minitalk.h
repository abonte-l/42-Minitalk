/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:02:37 by abonte-l          #+#    #+#             */
/*   Updated: 2022/01/05 15:46:57 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

# define ERROR -1
# define SUCCESS 0
# define ERROR_ARG_SERV "[ERROR]\n only <./server> needed \n[exit]\n"
# define ERROR_ARG_CLI "[ERROR]\n : ./client works only with 3 arg\n[exit]\n"
# define ERROR_PID "[ERROR]\nincorrect server's PID\n[exit]\n"
# define ERROR_SIGNAL "[ERROR]\nsignal error \n[exit]\n"
# define ERROR_SIGAC_SERV "[ERROR]\nError server sigaction\n"
# define ERROR_SIGAC_CLI "[ERROR]\nError client sigaction\n"
# define PID_SUCCESS "[SERVER LISTENING] PID successfully retrieve : "

int		ft_atoi(const char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
void	ft_putchar(char c);
void	check_pid_nb(char *str);

#endif