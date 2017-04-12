/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_large_positive_loop_test.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 22:23:21 by starrit           #+#    #+#             */
/*   Updated: 2017/02/11 23:24:35 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "libft.h"

int		large_positive_loop_test(void)
{
	char	*str;
	int		result;

	asprintf(&str, "%lld", LLONG_MAX + 1);
	if (ft_atoi(str) == atoi(str))
		result = 0;
	else
		result = -1;
	if (str)
		free(str);
	return (result);
}
