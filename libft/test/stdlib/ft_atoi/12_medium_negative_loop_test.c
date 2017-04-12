/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_medium_negative_loop_test.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 22:13:58 by starrit           #+#    #+#             */
/*   Updated: 2017/02/11 23:23:56 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int		medium_negative_loop_test(void)
{
	if (ft_atoi(ft_itoa(INT_MIN - 2523874)) == atoi(ft_itoa(INT_MIN - 2523874)))
		return (0);
	else
		return (-1);
}
