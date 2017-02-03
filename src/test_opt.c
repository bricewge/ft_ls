/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 21:44:43 by bwaegene          #+#    #+#             */
/*   Updated: 2017/02/03 22:17:27 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void print_getopt(int opt)
{
	printf("opterr: %d,\toptind: %d,\toptopt: %c,\toptreset: %d,\toptarg: %s,\t return: %c\n",
		   opterr, optind, optopt, optreset, optarg, opt);
}

int		main(int ac, char **av)
{
	int		bflag;
	char	*fvalue;
	int		opt;
	char	*optstring = "bf:";

	bflag = 0;
	fvalue = NULL;
	while ((opt = getopt(ac, av, optstring)) != -1)
	{
		print_getopt(opt);
		if (opt == 'b')
			bflag = 1;
		else if (opt == 'f')
			fvalue = optarg;
		else
		{
			break;
			usage("bf");
		}
	}
	print_getopt(opt);
	ft_putstr("bflag: ");
	ft_putnbr(bflag);
	ft_putstr(", fvalue: ");
	ft_putstr(fvalue);
	ft_putstr("\n\n");

	optreset = 1;
	optind = 1;
	while ((opt = ft_getopt(ac, av, optstring)) != -1)
	{
		print_getopt(opt);
		if (opt == 'b')
			bflag = 1;
		else if (opt == 'f')
			fvalue = optarg;
		else
		{
			break;
			usage("bf");
		}
	}
	print_getopt(opt);
	ft_putstr("bflag: ");
	ft_putnbr(bflag);
	ft_putstr(", fvalue: ");
	ft_putstr(fvalue);
	ft_putchar('\n');

	ac -= optind;
	av += optind;
	return (0);
}
