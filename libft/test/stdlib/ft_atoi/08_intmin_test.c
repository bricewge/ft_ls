/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_intmin_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 22:09:10 by starrit           #+#    #+#             */
/*   Updated: 2017/02/11 23:23:24 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int		intmin_test(void)
{
	if (ft_atoi(ft_itoa(INT_MIN)) == atoi(ft_itoa(INT_MIN)))
		return (0);
	else
		return (-1);
}
