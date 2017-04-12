/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_small_positive_loop_test.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 22:21:57 by starrit           #+#    #+#             */
/*   Updated: 2017/02/11 23:23:48 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int		small_positive_loop_test(void)
{
	if (ft_atoi(ft_itoa(INT_MAX + 1)) == atoi(ft_itoa(INT_MAX + 1)))
		return (0);
	else
		return (-1);
}
