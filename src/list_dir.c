/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 12:46:05 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 13:28:20 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_dir.h"

int		main(int ac, char **av)
{
	DIR			*dirp;
	t_dirent	*dp;

	if (ac == 2)
	{
		dirp = opendir(av[1]);
		if (dirp == NULL)
			return (1);
		while ((dp = readdir(dirp)) != NULL)
			if (*(dp->d_name) != '.')
				ft_putendl(dp->d_name);
	}
	return (0);
}
