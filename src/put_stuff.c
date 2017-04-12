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

static void	puttime(time_t clock)
{
	char *mtime;
	char *result;

	mtime = ctime(&clock);
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
	}
	ft_putstr(result);
	free(result);
}

/*
** Display link if it is a symlink.
*/

static void	putlink(t_ls entry, char *dirname)
{
	char	*linkname;
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
