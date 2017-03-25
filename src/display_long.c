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

// TODO fix leaks, memory mismanaged
static void	puttime(time_t clock)
{
	char *mtime;
	char *result;

	mtime = ctime(&clock);
	result = ft_strnew(12);
	if (mtime != NULL && result != NULL)
	{
		if (ft_abs(time(NULL) - clock) < 15768000)
			result = ft_strsub(mtime, 4, 12);
		else
		{
			result = ft_strsub(mtime, 4, 7);
			ft_strcpy(result + 7, ft_strsub(mtime, 19, 5));
		}
		/* free(mtime); */
	}
	ft_putstr(result);
	free(result);
}


/*
** Display the header on top of each directory entry in long format which
** contain the total number of blocks used by the entries of this directory.
*/

static void	display_blocks(t_ls *entry, int length)
{
	int i;
	int total;

	i = -1;
	total = 0;
	while (++i < length)
	{
		total += entry[i].stat.st_blocks;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}

char	*ft_pathjoin(const char *dir, const char *file)
{
	char *path;
	int i;

	i = 0;
	while (dir[i])
		++i;
	if (dir[i - 1] != '/')
	{
		path = ft_strjoin(dir, "/");
		path = ft_strjoinf(path, file, 1);
	}
	else
		path = ft_strjoin(dir, file);
	return(path);
}

/*
** Display link if it is a symlink.
*/

static void	putlink(t_ls entry, char *dirname)
{
	char 	*linkname;
	size_t	size;
	char	*path;

	if (S_ISLNK(entry.stat.st_mode))
	{
		size = 255;
		linkname = ft_strnew(size);
		path = ft_strjoin(dirname, "/");
		path = ft_strjoinf(path, entry.dirent.d_name, 1);
		readlink(path, linkname, size);
		if (error(entry.dirent.d_name))
		{
			ft_putstr(" -> ");
			ft_putstr(linkname);
		}
		free(linkname);
	}
}

void		putmajmin(t_ls entry)
{

	putnbrp(major(entry.stat.st_rdev), 3, 1);
	ft_putstr(", ");
	putnbrp(minor(entry.stat.st_rdev), 3, 1);
}

/*
** Display one line in the long format.
*/

void		putlongls(t_ls entry, char *dirname, int *padlen)
{
	ft_putstr(file_mode(entry, dirname));
	ft_putchar(' ');
	putnbrp(entry.stat.st_nlink, padlen[0], 1);
	ft_putchar(' ');
	putstrp(getpwuid(entry.stat.st_uid)->pw_name, padlen[1], 0);
	ft_putstr("  ");
	putstrp(getgrgid(entry.stat.st_gid)->gr_name, padlen[2], 0);
	ft_putstr("  ");
	if (file_type(entry.stat.st_mode) == 'c'
		|| file_type(entry.stat.st_mode) == 'b')
		putmajmin(entry);
	else
		putnbrp(entry.stat.st_size, padlen[3], 1);
	ft_putchar(' ');
	puttime(entry.stat.st_mtime);
	ft_putchar(' ');
	ft_putstr(entry.dirent.d_name);
	putlink(entry, dirname);
	ft_putchar('\n');
}

void		display_long(t_ls *entry, int length, char *dirname)
{
	int		i;
	int		padlen[4];

	padsize(entry, length, padlen);
	if (length > 0)
		display_blocks(entry, length);
	i = -1;
	while (++i < length)
		putlongls(entry[i], dirname, padlen);
}
