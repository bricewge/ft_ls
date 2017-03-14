/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:55:53 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/27 18:03:07 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isize(int nb)
{
	int		i;
	int		tmp;

	i = 1;
	tmp = nb;
	if (tmp < 0)
		++i;
	while ((tmp /= 10))
		++i;
	return (i);
}

char		*ft_itoa(int nb)
{
	int		i;
	char	*result;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_isize(nb);
	result = ft_strnew(i);
	if (result)
	{
		result[i] = '\0';
		if (nb < 0)
		{
			result[0] = '-';
			nb *= -1;
		}
		if (nb == 0)
			result[0] = '0';
		while (nb)
		{
			result[--i] = (nb % 10) + '0';
			nb /= 10;
		}
	}
	return (result);
}
