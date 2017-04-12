/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:58:38 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/29 10:29:23 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bsort(void *base, size_t nel, size_t width,
				int (*compar)(const void *, const void *))
{
	t_uint	i;
	int		swapped;
	void	*el1;
	void	*el2;

	if (nel <= 1)
		return ;
	swapped = 0;
	i = -1;
	while (++i < nel - 1)
	{
		el1 = base + (i * width);
		el2 = base + ((i + 1) * width);
		if (compar(el1, el2) > 0)
		{
			ft_swap(el1, el2, width);
			swapped = 1;
		}
	}
	if (swapped == 1)
		ft_bsort(base, nel, width, compar);
}
