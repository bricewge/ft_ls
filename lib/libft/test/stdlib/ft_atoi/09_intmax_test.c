/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_intmax_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 22:10:23 by starrit           #+#    #+#             */
/*   Updated: 2017/02/11 23:24:48 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int		intmax_test(void)
{
	if (ft_atoi(ft_itoa(INT_MAX)) == atoi(ft_itoa(INT_MAX)))
		return (0);
	else
		return (-1);
}
