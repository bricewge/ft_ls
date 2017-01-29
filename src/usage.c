/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:40:58 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/29 01:32:14 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	illegal_option(char *options, int illegal)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putendl_fd(options + illegal, 2);
	usage(options);
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
	exit (1);
}
