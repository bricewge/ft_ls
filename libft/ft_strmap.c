/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 11:28:17 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/26 12:19:25 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*result;

	result = NULL;
	if (s)
	{
		len = ft_strlen((char *)s);
		result = ft_strnew(len);
	}
	while (result && s[--len])
		result[len] = f(s[len]);
	return (result);
}
