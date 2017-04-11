/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_large_negative_loop_test.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 22:21:16 by starrit           #+#    #+#             */
/*   Updated: 2017/02/11 23:24:29 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "libft.h"

int		large_negative_loop_test(void)
{
	char	*str;
	int		result;

	asprintf(&str, "%lld", LLONG_MIN - 1);
	if (ft_atoi(str) == atoi(str))
		result = 0;
	else
		result = -1;
	if (str)
		free(str);
	return (result);
}
