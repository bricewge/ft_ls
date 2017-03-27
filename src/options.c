/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt		options(t_opt *opts)
{
	static t_opt	result = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	if (opts != NULL)
		result = *opts;
	return (result);
}

void		opt_parse(int *ac, char ***av)
{
	int		opt;
	t_opt	opts;

	opts = options(NULL);
	while ((opt = ft_getopt(*ac, *av, OPTIONS)) != -1)
	{
		if (opt == 'R')
			opts.recur = 1;
		else if (opt == 'a')
			opts.all = 1;
		else if (opt == '1')
		{
			opts.dlong = 0;
			opts.done = 1;
		}
		else if (opt == 'l')
		{
			opts.dlong = 1;
			opts.done = 0;
		}
		else if (opt == 'r')
			opts.sortrev = 1;
		else if (opt == 't')
			opts.sortmtime = 1;
		else
			usage(OPTIONS);
	}
	options(&opts);
	*ac -= optind;
	*av += optind;
}
