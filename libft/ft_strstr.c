/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 17:18:03 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/22 13:48:58 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int len_little;

	if (!*little)
		return ((char *)big);
	len_little = ft_strlen((char *)little);
	--big;
	while (*++big)
	{
		if (!ft_strncmp((char *)big, (char *)little, len_little))
			return ((char *)big);
	}
	return (NULL);
}
