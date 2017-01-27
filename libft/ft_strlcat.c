/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:21:36 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/24 16:45:05 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_initial_dst;
	size_t len_src;
	size_t i;

	len_initial_dst = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	i = 0;
	while (src[i] && size && i + len_initial_dst < size - 1)
	{
		dst[i + len_initial_dst] = src[i];
		i++;
	}
	if (!(len_initial_dst > size))
		dst[len_initial_dst + i] = '\0';
	return (len_src + (size < len_initial_dst ? size : len_initial_dst));
}
