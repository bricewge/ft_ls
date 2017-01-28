/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 00:24:33 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/29 00:24:48 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Display error in a identical way as ls.
*/

int		error(char *name, char *path)
{
	int		fd;
	char	*tmp;

	fd = 2;
	ft_putstr_fd(name, fd);
	ft_putstr_fd(": ", fd);
	if (path)
	{
		if (path[ft_strlen(path) - 1] != '/')
		{
			tmp = ft_basename(path);
			ft_putstr_fd(tmp, fd);
			free(tmp);
		}
		ft_putstr_fd(": ", fd);
	}
    tmp = strerror(errno);
	ft_putendl_fd(tmp, fd);
	free(tmp);
	return (1);
}
