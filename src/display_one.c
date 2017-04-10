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

void		display_one(t_ls *entry, int length, int dir)
{
	int i;

	i = -1;
	while (++i < length)
	{
		if (opt_needstat())
		{
			if (entry[i].stat.st_ino != 0)
				if (!(dir == 0 && file_type(entry[i].stat.st_mode) == 'd'))
					ft_putendl(entry[i].dirent.d_name);
		}
		else if (entry[i].dirent.d_name[0] != 0)
			if (!(dir == 0 && file_type(entry[i].stat.st_mode) == 'd'))
				ft_putendl(entry[i].dirent.d_name);
	}
}
