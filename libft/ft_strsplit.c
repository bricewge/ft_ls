/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 09:06:21 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/30 09:33:28 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wrdcnt(const char *s, char c)
{
	int		count;
	int		substr;

	count = 0;
	substr = 0;
	while (*s)
	{
		if (substr == 1 && *s == c)
			substr = 0;
		if (substr == 0 && *s != c)
		{
			substr = 1;
			++count;
		}
		++s;
	}
	return (count);
}

static int	wrdlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s && *s++ != c)
		++len;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		words;
	char	**result;

	if (!s)
		return (NULL);
	i = 0;
	words = wrdcnt(s, c);
	result = (char **)malloc(sizeof(*result) * (words + 1));
	if (!result)
		return (result);
	while (words--)
	{
		while (*s && *s == c)
			++s;
		result[i] = ft_strsub(s, 0, wrdlen(s, c));
		if (!result[i++])
			return (result);
		s += wrdlen(s, c);
	}
	result[i] = NULL;
	return (result);
}
