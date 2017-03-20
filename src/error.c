/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 00:24:33 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/29 01:16:39 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ls.h"

/*
** Store the name of the running executable
*/

char	*progname(char *name)
{
	static char *result;

	if (name != NULL)
		result = name;
	return (result);
}

/*
** Display error in a identical way as ls.
*/

int		error(char *path)
{
	int		fd;
	char	*tmp;

	if (errno != 0)
	{
		fd = 2;
		ft_putstr_fd(progname(NULL), fd);
		ft_putstr_fd(": ", fd);
		if (path)
		{
			if (errno == ENOENT || errno == ENOTDIR)
				ft_putstr_fd(path, fd);
			else if (path[ft_strlen(path) - 1] != '/')
			{
				tmp = ft_basename(path);
				ft_putstr_fd(tmp, fd);
				free(tmp);
			}
			ft_putstr_fd(": ", fd);
		}
		perror(NULL);
		errno = 0;
		return (0);
	}
	return (1);
}
