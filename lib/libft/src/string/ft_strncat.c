/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:06:35 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/23 15:05:46 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		len1;
	size_t		len2;

	len1 = ft_strlen(s1);
	len2 = 0;
	while (s2[len2] && len2 < n)
	{
		s1[len1 + len2] = s2[len2];
		len2++;
	}
	s1[len1 + len2] = '\0';
	return (s1);
}
