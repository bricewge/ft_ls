/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:58:44 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/29 05:50:12 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int i;
	int *result;

	if (min >= max)
		return (NULL);
	i = 0;
	result = (int*)malloc(sizeof(*result) * (max - min));
	while (i < (max - min))
	{
		result[i] = min + i;
		i++;
	}
	return (result);
}
