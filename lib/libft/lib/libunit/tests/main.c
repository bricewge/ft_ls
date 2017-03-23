/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:20:14 by bwaegene          #+#    #+#             */
/*   Updated: 2017/02/12 19:20:30 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdlib.h>

int	main(void)
{
	int		res_test[2];

	res_test[0] = 0;
	res_test[1] = 0;
	print_header();
	m_framework_launcher(res_test);
	return (print_total(res_test));
}
