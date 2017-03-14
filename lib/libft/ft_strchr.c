/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:27:53 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/21 15:35:25 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	--s;
	while (*++s)
		if (*s == (char)c)
			return ((char *)s);
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
