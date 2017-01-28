/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:40:58 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:29:32 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	illegal_option(char option)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putendl_fd(&option, 2);
}

int		test_options(int ac, char **av, char *options)
{
	int		i;

	i = 1;
	while (ac > i)
	{
		if (*av[i] == '-')
		{
			
		}
	}
}

void	usage(char *options)
{
	ft_putstr_fd("usage: ft_ls [-", 2);
	ft_putstr_fd(options, 2);
	ft_putendl_fd("] [file ...]", 2);
}
