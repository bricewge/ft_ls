/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:28:28 by bwaegene          #+#    #+#             */
/*   Updated: 2017/02/05 12:57:26 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		listl2(DIR *dirp, char *dirname)
{
	t_dirent	*dp;
	char		*nextdir;
	t_stat		buf;

	while ((dp = readdir(dirp)) != NULL)
	{
		if (!(ft_strequ(dp->d_name, ".") || ft_strequ(dp->d_name, "..")))
		{
			nextdir = pathjoin(dirname, dp->d_name);
			if (lstat(nextdir, &buf) == 0)
			{
				if (S_ISDIR(buf.st_mode))
				{
					listl_recur(nextdir);
					ft_putendl(nextdir);
				}
			}
			else
				error(nextdir);
			free(nextdir);
		}
	}
}

int				listl(char *dirname)
{
	DIR			*dirp;

	dirp = opendir(dirname);
	if (errno != 0)
		return (error(dirname));
	else
	{
		listl2(dirp, dirname);
		closedir(dirp);
		if (errno != 0)
			return (error(dirname));
	}
	return (0);
}
