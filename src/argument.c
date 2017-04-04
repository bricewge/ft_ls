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

static int stringcmp(const void *p1, const void *p2)
{
	char **c1;
	char **c2;

	c1 = (char **)p1;
	c2 = (char **)p2;
	return (ft_strcmp(*c1, *c2));
}


void	arg_sort(int argc, char ***argv)
{
	t_opt	opt;

	opt = options(NULL);
	if (opt.sortno)
		;
	else
		qsort(*argv, argc, sizeof(**argv), stringcmp);
}
