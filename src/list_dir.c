/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
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

	count = 0;
	dirp = opendir(dirname);
	if (error(dirname))
	{
		while ((dp = readdir(dirp)) != NULL)
			++count;
		closedir(dirp);
		error(dirname);
	}
	return(count);
}

void	dirent_store(t_ls *entry, t_stat *stat, t_dirent *dirent)
{
	entry->dirent = *dirent;
	entry->stat = *stat;
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
	t_stat		buf;

	i = -1;
	dirp = opendir(dirname);
	error(dirname);
	entry = (t_ls*)malloc(sizeof(*entry) * length);
	if (entry != NULL)
	{
		while (++i < length && (dp = readdir(dirp)) != NULL)
		{
			if (stat(dp->d_name, &buf) == 0)
				dirent_store(&entry[i], &buf, dp);
			else
				error(dp->d_name);
		}
		closedir(dirp);
		error(dirname);
	}
	return(entry);
}

// TODO add flags
void	dirent(char *dirname)
{
	t_ls		*dircont;
	int			length;

	length = dirent_cnt(dirname);
	// Store
	dircont = dir_store(dirname, length);
	// Sort
	/* qsort(dircont, length, sizeof(*dircont), alphacmp); */
	/* qsort(dircont, length, sizeof(*dircont), mtimecmp); */
	/* qsort(dircont, length, sizeof(*dircont), atimecmp); */
	// Display
	display_long(dircont, length);
	/* ft_putendl("------------------"); */
	/* display_one(dircont, length); */
	// Free
	free(dircont);
}

int		main(int ac, char **av)
{
	progname(av[0]);
	if (ac == 2)
	{
		dirent(av[1]);
	}
	ft_putnbr(sizeof(t_opt));
	return (0);
}
