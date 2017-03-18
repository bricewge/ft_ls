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
int		dirent_cnt(char *dirname, char *progname)
{
	int			count;
	DIR			*dirp;
	t_dirent	*dp;

	count = 0;
	dirp = opendir(dirname);
	if (errno != 0)
		error(progname, dirname);
	else
	{
		while ((dp = readdir(dirp)) != NULL)
			++count;
		closedir(dirp);
		if (errno != 0)
			error(progname, dirname);
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
t_ls	*dir_store(char *dirname, int length, char *progname)
{
	t_ls		*entry;
	int			i;
	DIR			*dirp;
	t_dirent	*dp;
	t_stat		buf;

	i = -1;
	dirp = opendir(dirname);
	if (errno != 0)
		error(progname, dirname);
	entry = (t_ls*)malloc(sizeof(*entry) * length);
	if (entry != NULL)
	{
		while (++i < length && (dp = readdir(dirp)) != NULL)
		{
			if (stat(dp->d_name, &buf) == 0)
				dirent_store(&entry[i], &buf, dp);
			else
				error(progname, dp->d_name);
		}
		closedir(dirp);
		if (errno != 0)
			error(progname, dirname);
	}
	return(entry);
}

// TODO add flags
void	dirent(char *dirname, char *progname)
{
	t_ls		*dircont;
	int			length;
	int			i = 0;

	length = dirent_cnt(dirname, progname);
	// Store
	dircont = dir_store(dirname, length, progname);
	//DEBUG
	while (i < length)
	{
		++i;
	}
	// Sort
	// Display
	display_long(dircont, length);
	ft_putchar('\n');
	display_one(dircont, length);
	// Free
}


int		main(int ac, char **av)
{
	/* DIR			*dirp; */
	/* t_dirent	*dp; */

	if (ac == 2)
	{
		dirent(av[1], av[0]);
		/* dirp = opendir(av[1]); */
		/* if (errno != 0) */
		/* 	error(av[0], av[1]); */
		/* while ((dp = readdir(dirp)) != NULL) */
		/* 	if (*(dp->d_name) != '.') */
		/* 		ft_putendl(dp->d_name); */
		/* /\* ft_putnbr(cnt_dirent(av[1], av[0])); *\/ */
		/* closedir(dirp); */
		/* if (errno != 0) */
		/* 	error(av[0], av[1]); */
		/* list(av[1], av[0]); */
	}
	return (0);
}
