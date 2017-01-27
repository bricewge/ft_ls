/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 14:39:21 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/21 12:49:21 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*result;

	result = NULL;
	if (s1 && s2)
	{
		len1 = ft_strlen((char *)s1);
		len2 = ft_strlen((char *)s2);
		result = (char *)malloc(sizeof(*result) * (len1 + len2 + 1));
		if (result)
		{
			result[len1 + len2] = '\0';
			while (--len2 >= 0)
				result[len1 + len2] = s2[len2];
			while (--len1 >= 0)
				result[len1] = s1[len1];
		}
	}
	return (result);
}
