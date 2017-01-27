/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 10:52:26 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/22 13:50:12 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = -1;
	tmp1 = (unsigned char *)--s1;
	tmp2 = (unsigned char *)--s2;
	while (++i < n)
		if (*++tmp1 != *++tmp2 || *tmp1 == '\0' || *tmp2 == '\0')
			return (*tmp1 - *tmp2);
	return (0);
}
