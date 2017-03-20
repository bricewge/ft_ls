/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:58:38 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/29 10:29:23 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		alphacmp(const void *p1, const void *p2)
{
	char *c1;
	char *c2;

	c1 = ((t_ls*)p1)->dirent.d_name;
	c2 = ((t_ls*)p2)->dirent.d_name;
	return(ft_strcmp(c1, c2));
}

// TODO fix it, not the same result as ls but wotking
int		mtimecmp(const void *p1, const void *p2)
{
	time_t	t1;
	time_t	t2;

	t1 = ((t_ls*)p1)->stat.st_mtime;
	t2 = ((t_ls*)p2)->stat.st_mtime;
	return(t2 - t1);
}

// TODO doesn't seem to work
int		atimecmp(const void *p1, const void *p2)
{
	time_t	t1;
	time_t	t2;

	t1 = ((t_ls*)p1)->stat.st_atime;
	t2 = ((t_ls*)p2)->stat.st_atime;
	return(t2 - t1);
}

/* void	ft_sort(void *base, size_t nel, size_t width, */
/* 					int (*compar)(const void *, const void *)); */
/* { */

/* } */
