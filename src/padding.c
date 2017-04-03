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

/*
** Padd a string to the left (pos=0) or the right (pos=1)
*/

char	*padding(char *str, int totallen, int pos)
{
	int		len;
	char	*start;
	char	*padded;

	len =  ft_strlen(str);
	padded = ft_strnew(totallen);
	ft_memset(padded, ' ', totallen);
	start = padded;
	if (pos == 0)
		start = padded;
	else if (pos == 1)
		start = padded + (totallen - len);
	ft_memcpy(start, str, len);
	return (padded);
}

void	putstrp(char *str, int len, int pos)
{
	char	*strp;

	strp = padding(str, len, pos);
	ft_putstr(strp);
	free(strp);
}

void	putnbrp(int nbr, int len, int pos)
{
	char	*str;
	char	*strp;

	str = ft_itoa(nbr);
	strp = padding(str, len, pos);
	ft_putstr(strp);
	free(str);
	free(strp);
}

void	padsize(t_ls *entry, int length, int *padlen)
{
	int i;
	int tmp;

	i = -1;
	while (++i < 4)
		padlen[i] = 0;
	i = -1;
	while (++i < length)
	{
		tmp = ft_nbrlen(entry[i].stat.st_nlink);
		if (tmp > padlen[0])
			padlen[0] = tmp;
		tmp = ft_strlen(getpwuid(entry[i].stat.st_uid)->pw_name);
		if (tmp > padlen[1])
			padlen[1] = tmp;
		tmp = ft_strlen(getgrgid(entry[i].stat.st_gid)->gr_name);
		if (tmp > padlen[2])
			padlen[2] = tmp;
		tmp = ft_nbrlen(entry[i].stat.st_size);
		if (file_type(entry[i].stat.st_mode) == 'c'
			|| file_type(entry[i].stat.st_mode) == 'b')
			padlen[3] = 8;
		else if (tmp > padlen[3])
			padlen[3] = tmp;
	}
}
