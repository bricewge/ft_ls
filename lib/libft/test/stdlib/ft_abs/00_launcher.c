/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 13:36:58 by bwaegene          #+#    #+#             */
/*   Updated: 2017/02/12 16:11:56 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "libunit.h"

void		ft_abs_launcher(int *res_test)
{
	t_test *testlist;

	testlist = NULL;
	ft_putendl("FT_ABS:");
	load_test(&testlist, "Positive", &ft_abs_positive_test);
	load_test(&testlist, "Negative", &ft_abs_negative_test);
	load_test(&testlist, "Zero", &ft_abs_zero_test);
	launch_tests(&testlist, res_test);
	del_test_lst(&testlist);
}
