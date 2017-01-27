/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 12:22:24 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/26 12:23:56 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	size_t	len;
	char	*result;

	result = NULL;
	if (s)
	{
		len = ft_strlen((char *)s);
		result = ft_strnew(len);
	}
	i = -1;
	while (result && s[++i])
		result[i] = f(i, s[i]);
	return (result);
}
