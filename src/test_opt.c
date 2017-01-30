/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 21:44:43 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/30 02:54:30 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int		main(int ac, char **av)
{
	int		bflag;
	char	*fvalue;
	int		opt;

	bflag = 0;
	fvalue = NULL;
	while ((opt = getopt(ac, av, "bf:" )) != -1)
	{
		if (opt == 'b')
			bflag = 1;
		else if (opt == 'f')
			fvalue = av[(uintptr_t)optind - 1];
		else
		{
			usage("bf");
		}
	}
	ft_putstr("bflag: ");
	ft_putnbr(bflag);
	ft_putstr(", fvalue: ");
	ft_putendl(fvalue);
	ac -= optind;
	av += optind;
	return (0);
}
