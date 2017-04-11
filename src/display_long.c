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
** Display the header on top of each directory entry in long format which
** contain the total number of blocks used by the entries of this directory.
*/

static void	display_blocks(t_ls *entry, int length)
{
	int		i;
	int		total;

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
	return (path);
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

void		display_long(t_ls *entry, int length, char *dirname, int flag[2])
{
	int		i;
	int		padlen[4];

	i = -1;
	padsize(entry, length, padlen, flag[1]);
	if (valid_entries(entry, length) > 0 && flag[0] == 1)
		display_blocks(entry, length);
	while (++i < length)
		if (entry[i].stat.st_ino != 0)
			if (!(flag[1] == 0 && file_type(entry[i].stat.st_mode) == 'd'))
				putlongls(entry[i], dirname, padlen);
}
