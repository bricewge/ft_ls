/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	/* int		i; */

	progname(av[0]);
	opt_parse(&ac, &av);
	arg_sort(ac, &av);
	arg_files(ac, av);
	/* i = 0; */
	/* while (ac > i) */
	/* { */
	/* 	if (av[i] != NULL) */
	/* 		/\* ft_putendl(av[i]); *\/ */
	/* 		dirent(av[i], ac); */
	/* 	i++; */
	/* } */
	if (ac == 0)
		dirent(".", ac);
	return (0);
}
