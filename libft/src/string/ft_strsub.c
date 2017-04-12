/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:51:40 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/26 14:37:11 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*result;

	result = NULL;
	if (s)
	{
		i = -1;
		result = (char *)malloc(sizeof(*result) * len + 1);
		if (result)
		{
			while (++i < len)
				result[i] = s[start + i];
			result[i] = '\0';
		}
	}
	return (result);
}
