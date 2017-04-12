/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:20:14 by bwaegene          #+#    #+#             */
/*   Updated: 2017/02/12 16:09:46 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "libunit.h"

int	main(void)
{
	int	res_test[2];

	res_test[0] = 0;
	res_test[1] = 0;
	print_header();
	ft_atoi_launcher(res_test);
	ft_abs_launcher(res_test);
	ft_nbrlen_launcher(res_test);
	return (print_total(res_test));
}
