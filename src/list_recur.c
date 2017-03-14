/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_recur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:28:28 by bwaegene          #+#    #+#             */
/*   Updated: 2017/02/05 12:57:26 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Similar to the command
** find $mydir -type d -name '*' 2>/dev/null | wc -l
*/
int 	listl_recur(char *dirname, char *progname)
{
	char		*nextdir;
	t_stat		buf;
	DIR			*dirp;
	t_dirent	*dp;

	dirp = opendir(dirname);
	if (errno != 0)
		return(error(progname, dirname));
	else
	{
		while ((dp = readdir(dirp)) != NULL)
		{
			if ( !(ft_strequ(dp->d_name, ".") || ft_strequ(dp->d_name, "..") ))
			{
				nextdir = ft_strjoin(dirname, "/");
				nextdir = ft_strjoinf(nextdir, dp->d_name, 1);
				if (lstat(nextdir, &buf) == 0)
				{
					if (S_ISDIR(buf.st_mode))
					{
						listl_recur(nextdir, progname);
						ft_putendl(nextdir);
					}
				}
				else
					error(progname, nextdir);
				free(nextdir);
			}
		}
		if (errno != 0)
			return (error(progname, dirname));
		else
			closedir(dirp);
	}
	return(0);
}

int		main(int ac, char **av)
{
	int		result;

	result = 0;
	if (ac == 2)
	{
		return(!listl_recur(av[1], av[0]));
	}
	return (1);
}
