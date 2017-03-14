/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:00:52 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/23 10:55:08 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int		i;
	void	*c_location;

	i = -1;
	c_location = ft_memchr(src, c, n);
	if (!c_location)
	{
		ft_memcpy(dst, src, n);
		return (NULL);
	}
	while (src + ++i != c_location + 1)
		((t_byte *)dst)[i] = ((t_byte *)src)[i];
	return (dst + i);
}
