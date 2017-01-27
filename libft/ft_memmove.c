/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 10:58:24 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/23 11:14:44 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = -1;
	if (src < dst)
		ft_memcpy(dst, src, len);
	else if (src > dst)
		while (++i < len)
			((t_byte *)dst)[i] = ((t_byte *)src)[i];
	return (dst);
}
