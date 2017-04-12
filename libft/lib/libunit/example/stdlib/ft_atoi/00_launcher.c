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

void		ft_atoi_launcher(int *res_test)
{
	t_test *testlist;

	testlist = NULL;
	ft_putendl("FT_ATOI:");
	load_test(&testlist, "Basic positive", &basic_positive_test);
	load_test(&testlist, "Basic negative", &basic_negative_test);
	load_test(&testlist, "Basic jump", &basic_jump_test);
	load_test(&testlist, "Null", &null_test);
	load_test(&testlist, "Error", &error_test);
	load_test(&testlist, "Error stop", &error_stop_test);
	load_test(&testlist, "Error signe", &error_signe_test);
	load_test(&testlist, "Intmin", &intmin_test);
	load_test(&testlist, "Intmax", &intmax_test);
	load_test(&testlist, "Small negative loop", &small_negative_loop_test);
	load_test(&testlist, "Small positive loop", &small_positive_loop_test);
	load_test(&testlist, "Medium negative loop", &medium_negative_loop_test);
	load_test(&testlist, "Medium positive loop", &medium_positive_loop_test);
	load_test(&testlist, "Large negative loop", &large_negative_loop_test);
	load_test(&testlist, "Large positive loop", &large_positive_loop_test);
	launch_tests(&testlist, res_test);
	del_test_lst(&testlist);
}
