/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display-file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:58:38 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/29 10:29:23 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	store_fcont(t_ls *file, char **path, int *dirs)
{
	t_stat	buf;
	int		st;

	if (options(NULL).done)
	{
		st = lstat(*path, &buf);
		if (st == 0)
			if (file_type(buf.st_mode) == 'l')
				st = stat(*path, &buf);
	}
	else
		st = lstat(*path, &buf);
	if (st == 0)
	{
		if (file_type(buf.st_mode) != 'd')
		{
			ft_strcpy(file->dirent.d_name, *path);
			file->stat = buf;
			*path = NULL;
		}
		else
		{
			*dirs = 1;
			return (0);
		}
	}
	else
	{
		error(*path);
		*path = NULL;
		return (0);
	}
	return (1);
}

/*
** Display files which where passed in the arguments.
*/
void	arg_files(int ac, char **argv)
{
	t_opt	opts;
	int		i;
	t_ls	*fcont;
	int		files;
	int		dirs;

	opts = options(NULL);
	i = -1;
	files = 0;
	dirs = 0;
	fcont = (t_ls*)malloc(sizeof(*fcont) * ac);
	while (++i < ac)
	{
		files += store_fcont(fcont + i, &(argv[i]), &dirs);
	}
	if (files)
	{
		if (opts.sortno)
			;
		else if (opts.sortatime)
			qsort(fcont, ac, sizeof(*fcont), atimecmp);
		else if (opts.sortmtime)
			qsort(fcont, ac, sizeof(*fcont), mtimecmp);
		else
			qsort(fcont, ac, sizeof(*fcont), alphacmp);
		if (opts.sortrev)
			ft_reverse(fcont, ac, sizeof(*fcont));
		if (opts.done)
			display_one(fcont, ac);
		else if (opts.dlong)
			display_long(fcont, ac, ".", 0);
	}
	free(fcont);
	if (files && dirs)
		ft_putchar('\n');
}
