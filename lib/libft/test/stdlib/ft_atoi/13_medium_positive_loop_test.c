/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_medium_positive_loop_test.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 22:22:36 by starrit           #+#    #+#             */
/*   Updated: 2017/02/11 23:24:23 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int		medium_positive_loop_test(void)
{
	if (ft_atoi(ft_itoa(INT_MAX + 2564257)) == atoi(ft_itoa(INT_MAX + 2564257)))
		return (0);
	else
		return (-1);
}
