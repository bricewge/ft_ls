/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *p1, void *p2, size_t size)
{
	void *tmp;

	tmp = (void *)malloc(size);
	if (tmp)
	{
		ft_memcpy(tmp, p1, size);
		ft_memcpy(p1, p2, size);
		ft_memcpy(p2, tmp, size);
		free(tmp);
	}
}
