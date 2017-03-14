/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:15:47 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/29 01:32:46 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	file_type(mode_t mode)
{
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISBLK(mode))
		return ('b');
	if (S_ISFIFO(mode))
		return ('p');
	if (S_ISLNK(mode))
		return ('l');
	if (S_ISSOCK(mode))
		return ('s');
	return ('-');
}

char		*file_mode(mode_t mode)
{
	char	*result;

	result = ft_strdup("---------- ");
	result[0] = file_type(mode);
	if (mode & S_IRUSR)
		result[1] = 'r';
	if (mode & S_IWUSR)
		result[2] = 'w';
	if (mode & S_IXUSR)
		result[3] = 'x';
	if (mode & S_IRGRP)
		result[4] = 'r';
	if (mode & S_IWGRP)
		result[5] = 'w';
	if (mode & S_IXGRP)
		result[6] = 'x';
	if (mode & S_IROTH)
		result[7] = 'r';
	if (mode & S_IWOTH)
		result[8] = 'w';
	if (mode & S_IXOTH)
		result[9] = 'x';
	return (result);
}
