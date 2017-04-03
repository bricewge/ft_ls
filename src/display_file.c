/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display-file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:58:38 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/29 10:29:23 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	store_fcont(t_ls *file, char **path)
{
	t_stat	buf;

	if (lstat(*path, &buf) == 0)
	{
		if (file_type(buf.st_mode) == '-')
		{
			ft_strcpy(file->dirent.d_name, *path);
			file->stat = buf;
			*path = NULL;
		}
		else
			return (0);
	}
	else
	{
		error(*path);
		*path = NULL;
		return (0);
	}
	return (1);
}

/*
** Display files which where passed in the arguments.
*/
void	arg_files(int ac, char **argv)
{
	t_opt	opts;
	int		i;
	t_ls	*fcont;
	int		res;

	opts = options(NULL);
	i = -1;
	res = 0;
	fcont = (t_ls*)malloc(sizeof(*fcont) * ac);
	while (++i < ac)
	{
		res += store_fcont(fcont + i, &(argv[i]));
	}
	if (opts.done)
		display_one(fcont, ac);
	else if (opts.dlong)
		display_long(fcont, ac, ".", 0);
	free(fcont);
	if (res)
		ft_putchar('\n');
}
