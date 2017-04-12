/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_negative_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 21:56:24 by starrit           #+#    #+#             */
/*   Updated: 2017/02/12 13:04:59 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_abs_negative_test(void)
{
	int	nbr;

	nbr = -789;
	if (ft_abs(nbr) == abs(nbr))
		return (0);
	else
		return (-1);
}
