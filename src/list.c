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

int 	listl(char *dirname)
{
	char		*nextdir;
	t_stat		buf;
	DIR			*dirp;
	t_dirent	*dp;

	dirp = opendir(dirname);
	if (errno != 0)
		return(error(dirname));
	else
	{
		while ((dp = readdir(dirp)) != NULL)
		{
			if ( !(ft_strequ(dp->d_name, ".") || ft_strequ(dp->d_name, "..")) )
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
		closedir(dirp);
		if (errno != 0)
			return (error(dirname));
	}
	return(0);
}
