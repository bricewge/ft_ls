/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:57:43 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/22 13:18:18 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	t_byte *tmp1;
	t_byte *tmp2;

	i = -1;
	tmp1 = (t_byte *)--s1;
	tmp2 = (t_byte *)--s2;
	while (++i < n)
		if (*++tmp1 != *++tmp2)
			return (*tmp1 - *tmp2);
	return (0);
}
