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

#include <sys/types.h>
#include <sys/acl.h>
#include <sys/xattr.h>
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

char		file_xattracl(t_ls entry, char *dirname)
{
	char	result;
	char	*path;
	acl_t	acl;
	int 	xattr;

	result = ' ';
	path = ft_pathjoin(dirname, entry.dirent.d_name);
	acl  = acl_get_file(path, ACL_TYPE_EXTENDED);
	if (acl)
	{
		result = '+';
		acl_free((void *)acl);
	}
	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		result = '@';
	/* else if (xattr == -1) */
	errno = 0;
	free(path);
	return (result);
}

char	file_operm(mode_t mode)
{
	if (mode & S_IXOTH && mode & S_ISVTX)
		return ('t');
	else if (mode & S_ISVTX)
		return ('T');
	else if (mode & S_IXOTH)
		return ('x');
	else
		return ('-');
}

char	file_gperm(mode_t mode)
{
	if (mode & S_IXGRP && mode & S_ISGID)
		return ('s');
	else if (mode & S_ISGID)
		return ('S');
	else if (mode & S_IXGRP)
		return ('x');
	else
		return ('-');
}

char	file_uperm(mode_t mode)
{
	if (mode & S_IXUSR && mode & S_ISUID)
		return ('s');
	else if (mode & S_ISUID)
		return ('S');
	else if (mode & S_IXUSR)
		return ('x');
	else
		return ('-');
}

char		*file_mode(t_ls entry, char *dirname)
{
	char	*result;

	result = ft_strdup("---------- ");
	result[0] = file_type(entry.stat.st_mode);
	if (entry.stat.st_mode & S_IRUSR)
		result[1] = 'r';
	if (entry.stat.st_mode & S_IWUSR)
		result[2] = 'w';
	result[3] = file_uperm(entry.stat.st_mode);
	if (entry.stat.st_mode & S_IRGRP)
		result[4] = 'r';
	if (entry.stat.st_mode & S_IWGRP)
		result[5] = 'w';
	result[6] = file_gperm(entry.stat.st_mode);
	if (entry.stat.st_mode & S_IROTH)
		result[7] = 'r';
	if (entry.stat.st_mode & S_IWOTH)
		result[8] = 'w';
	result[9] = file_operm(entry.stat.st_mode);
	result[10] = file_xattracl(entry, dirname);
	return (result);
}
