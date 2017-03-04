/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:52:29 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/29 00:30:58 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char *listl_time(time_t clock)
{
	char *mtime;
	char *result;

	mtime = ctime(&clock);
	result = ft_strnew(12);
	if (time(NULL) - clock < 15768000)
		result = ft_strsub(mtime, 4, 12);
	else
	{
		result = ft_strsub(mtime, 4, 7);
		ft_strcpy(result + 7, ft_strsub(mtime, 19, 5));
	}
	return(result);
}

void	*listl_display(t_stat buf)
{
	ft_putstr(file_mode((buf.st_mode)));
	ft_putchar(' ');
	ft_putnbr(buf.st_nlink);
	ft_putchar(' ');
	ft_putstr(getpwuid(buf.st_uid)->pw_name);
	ft_putstr("  ");
	ft_putstr(getgrgid(buf.st_gid)->gr_name);
	ft_putstr("  ");
	ft_putnbr(buf.st_size);
	ft_putchar(' ');
	ft_putstr(listl_time(buf.st_mtime));
	ft_putchar(' ');
	ft_putendl(av[1]);
}

int		main(int ac, char **av)
{
	t_stat	buf;

	if (ac == 2)
	{
		if (stat(av[1], &buf) == 0)
		{
			listl_display(buf);
		}
	}
	return (0);
}
