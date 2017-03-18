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

static char	*timetostr(time_t clock)
{
	char *mtime;
	char *result;

	mtime = ctime(&clock);
	result = ft_strnew(12);
	if (time(NULL) - clock < 15768000)
		result = ft_strsub(mtime, 4, 12);
	else
	{
		result = ft_strsub(mtime, 4, 7);
		ft_strcpy(result + 7, ft_strsub(mtime, 19, 5));
	}
	return (result);
}

void		display_one(t_ls *entry, int length)
{
	int i;

	i = -1;
	while (++i < length)
		ft_putendl(entry[i].dirent.d_name);
}

void		display_long(t_ls *entry, int length)
{
	int i;

	i = -1;
	while (++i < length)
	{
		ft_putstr(file_mode((entry[i].stat.st_mode)));
		ft_putchar(' ');
		ft_putnbr(entry[i].stat.st_nlink);
		ft_putchar(' ');
		ft_putstr(getpwuid(entry[i].stat.st_uid)->pw_name);
		ft_putstr("  ");
		ft_putstr(getgrgid(entry[i].stat.st_gid)->gr_name);
		ft_putstr("  ");
		ft_putnbr(entry[i].stat.st_size);
		ft_putchar(' ');
		ft_putstr(timetostr(entry[i].stat.st_mtime));
		ft_putchar(' ');
		ft_putendl(entry[i].dirent.d_name);
	}
}
