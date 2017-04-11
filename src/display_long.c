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
	/* ft_putchar('\n'); */
	/* ft_putnbr(ft_strlen(mtime)); */
	/* ft_putchar('\n'); */
	/* ft_putstr(mtime); */
	/* ft_putchar('\n'); */
	result = ft_strnew(ft_strlen(mtime));
	if (mtime != NULL && result != NULL)
	{
		if (ft_abs(time(NULL) - clock) < 15768000)
			result = ft_strsub(mtime, 4, 12);
		else
		{
			result = ft_strsub(mtime, 4, 6);
			ft_strcpy(result + 6, "  ");
			ft_strcpy(result + 8, ft_strtrim(mtime + 19));
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

char		*ft_pathjoin(const char *dir, const char *file)
{
	char	*path;
	int		len;

	len = ft_strlen(dir);
	if (dir[len - 1] != '/')
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
		if (entry.dirent.d_name[0] == '/')
			path = entry.dirent.d_name;
		else
		{
			path = ft_strjoin(dirname, "/");
			path = ft_strjoinf(path, entry.dirent.d_name, 1);
		}
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

void		putdirname(char *dir, int *first)
{
	if (*first == 0)
		*first = 1;
	else
		ft_putchar('\n');
	ft_putstr(dir);
	ft_putendl(":");
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

/*
** Return the number of valid entries. The length can be deseptive since it is
** the number of valid entries in a directory but some of thoses entries my fail
** a stat/lstat.
*/
int			valid_entries(t_ls *entry, int length)
{
	int		i;
	int		result;

	result = 0;
	i = -1;
	while (++i < length && entry)
	{
		if (entry[i].stat.st_ino != 0)
			++result;
	}
	return (result);
}

void			display_long(t_ls *entry, int length, char *dirname, int flag[2])
{
	int			i;
	int			padlen[4];

	i = -1;
	padsize(entry, length, padlen, flag[1]);
	if (valid_entries(entry, length) > 0 && flag[0] == 1)
		display_blocks(entry, length);
	while (++i < length)
	{
		if (entry[i].stat.st_ino != 0)
			if (!(flag[1] == 0 && file_type(entry[i].stat.st_mode) == 'd'))
				putlongls(entry[i], dirname, padlen);
		/* else */
		/* { */
		/* 	errno = EACCES; */
		/* 	error(entry[i].dirent.d_name); */
		/* } */
	}
}
