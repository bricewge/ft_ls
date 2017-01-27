/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:54:03 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/21 13:54:27 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return a new string resulting of the concatenation of the two string. If it
** succed it also free the first string (1), the second string (2), both (3) or
** none (0).
*/

char	*ft_strjoinf(char const *s1, char const *s2, int nb)
{
	char *result;

	result = ft_strjoin(s1, s2);
	if (result)
	{
		if (nb == 1 || nb == 3)
			free((char *)s1);
		if (nb == 2 || nb == 3)
			free((char *)s2);
	}
	return (result);
}
