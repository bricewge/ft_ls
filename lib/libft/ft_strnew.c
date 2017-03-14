/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 10:30:13 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/26 11:01:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;

	result = (char *)malloc(sizeof(*result) * size + 1);
	if (result)
	{
		ft_memset(result, 0, size + 1);
		return (result);
	}
	return (NULL);
}
