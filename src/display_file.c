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

static int	store_fcont2(t_ls *file, char **path, int st1, t_stat buf1)
{
	if (st1 == 0)
	{
		ft_strcpy(file->dirent.d_name, *path);
		file->stat = buf1;
		*path = NULL;
		if (file_type(buf1.st_mode) == 'd')
			return (0);
	}
	else
	{
		error(*path);
		*path = NULL;
		return (0);
	}
	return (1);
}

static int	store_fcont(t_ls *file, char **path)
{
	t_stat	buf1;
	t_stat	buf2;
	int		st1;
	int		st2;

	st1 = lstat(*path, &buf1);
	st2 = 0;
	if (options(NULL).done)
	{
		if (st1 == 0)
		{
			errno = 0;
			if (file_type(buf1.st_mode) == 'l')
			{
				st2 = stat(*path, &buf2);
				if (st2 == 0)
					buf1 = buf2;
			}
		}
	}
	return (store_fcont2(file, path, st1, buf1));
}

void		arg_dirs(t_ls *entry, int length, int pdirn)
{
	int		i;

	i = -1;
	while (++i < length)
	{
		if (file_type(entry[i].stat.st_mode) == 'd')
			dirent(entry[i].dirent.d_name, pdirn);
	}
}

void		arg_files2(t_ls *fcont, int ac, int distype[], char *dirname)
{
	t_opt	opts;

	opts = options(NULL);
	if (opts.sortno)
		;
	else if (opts.sortatime)
		ft_bsort(fcont, ac, sizeof(*fcont), atimecmp);
	else if (opts.sortmtime)
		ft_bsort(fcont, ac, sizeof(*fcont), mtimecmp);
	else
		ft_bsort(fcont, ac, sizeof(*fcont), alphacmp);
	if (opts.sortrev)
		ft_reverse(fcont, ac, sizeof(*fcont));
	if (opts.done)
		display_one(fcont, ac, distype[0]);
	else if (opts.dlong)
		display_long(fcont, ac, dirname, distype);
}

/*
** Display files which where passed in the arguments.
*/

void		arg_files(int ac, char **argv)
{
	int		i;
	t_ls	*fcont;
	int		files;

	i = -1;
	files = 0;
	fcont = (t_ls*)malloc(sizeof(*fcont) * ac);
	while (++i < ac)
	{
		files += store_fcont(fcont + i, &(argv[i]));
	}
	if (files)
		arg_files2(fcont, ac, (int[]){0, 0}, ".");
	if (files && ac - files)
		ft_putchar('\n');
	arg_dirs(fcont, ac, ac - files);
	free(fcont);
}
