/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 12:46:05 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/29 01:13:52 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Return the total number of entries in a directory.
*/
int		dirent_cnt(char *dirname)
{
	int			count;
	DIR			*dirp;
	t_dirent	*dp;
	t_opt		opts;

	count = 0;
	opts = options(NULL);
	dirp = opendir(dirname);
	if (error(dirname))
	{
		while ((dp = readdir(dirp)) != NULL)
		{
			if (opts.all == 0 && *(dp->d_name) == '.')
				;
			else
				++count;
		}
		closedir(dirp);
		error(dirname);
	}
	return(count);
}

static int	dirent_store(t_ls *entry, t_dirent *dirent, char *dirname)
{
	t_stat		buf;
	char		*path;

	if (options(NULL).all == 0 && *(dirent->d_name) == '.')
		return (0);
	path = ft_strjoin(dirname, "/");
	path = ft_strjoinf(path, dirent->d_name, 1);
	if (lstat(path, &buf) == 0)
	{
		entry->dirent = *dirent;
		entry->stat = buf;
	}
	else
		error(dirent->d_name);
	free(path);
	return (1);
}

/*
** Store the metadata of each entries in a given directory.
*/
t_ls	*dir_store(char *dirname, int length)
{
	t_ls		*entry;
	int			i;
	DIR			*dirp;
	t_dirent	*dp;

	dirp = opendir(dirname);
	error(dirname);
	entry = (t_ls*)malloc(sizeof(*entry) * length);
	if (entry != NULL)
	{
		i = 0;
		while (i < length && (dp = readdir(dirp)) != NULL)
			i += dirent_store(&entry[i], dp, dirname);
		closedir(dirp);
		error(dirname);
	}
	return(entry);
}

void	dirent(char *dirname)
{
	t_opt		opts;
	t_ls		*dircont;
	int			length;

	opts = options(NULL);
	length = dirent_cnt(dirname);
	dircont = dir_store(dirname, length);
	if (opts.sortno)
		;
	else if (opts.sortatime)
		qsort(dircont, length, sizeof(*dircont), atimecmp);
	else if (opts.sortmtime)
		qsort(dircont, length, sizeof(*dircont), mtimecmp);
	else
		qsort(dircont, length, sizeof(*dircont), alphacmp);
	if (opts.done)
		display_one(dircont, length);
	else if (opts.dlong)
		display_long(dircont, length, dirname);
	free(dircont);
}
