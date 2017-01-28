/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 12:46:05 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/29 00:29:33 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	DIR			*dirp;
	t_dirent	*dp;

	if (ac == 2)
	{
		dirp = opendir(av[1]);
		if (errno != 0)
			return (error(av[0], av[1]));
		while ((dp = readdir(dirp)) != NULL)
			if (*(dp->d_name) != '.')
				ft_putendl(dp->d_name);
		if (errno != 0)
			return (error(av[0], av[1]));
	}
	return (0);
}
