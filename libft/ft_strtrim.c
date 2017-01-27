/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 15:04:49 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/27 11:31:18 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		start;
	int		stop;
	char	*result;

	result = NULL;
	if (s)
	{
		len = ft_strlen((char *)s);
		start = 0;
		stop = len - 1;
		while (s[start] && ft_isspace(s[start]))
			++start;
		while (s[stop] && ft_isspace(s[stop]))
			--stop;
		if (start < stop)
			result = ft_strsub(s, start, len - start - (len - 1 - stop));
		else
			result = ft_strdup("");
	}
	return (result);
}
