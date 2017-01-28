/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 23:25:46 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/29 00:15:20 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the base portion of a pathname in a new string. Similar to POSIX
** basename but doesn't modify path and retrun a new string.
*/

char	*ft_basename(char *path)
{
	int		i;

	if (!path || !*path)
		return (ft_strdup("."));
	i = ft_strlen(path) - 1;
	while (i && path[i] == '/')
		path[i--] = '\0';
	while (i && path[i - 1] != '/')
		--i;
	return (ft_strdup(path + i));
}
