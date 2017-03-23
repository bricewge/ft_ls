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
	load_test(&testlist, "Basic positive test", &basic_positive_test);
	load_test(&testlist, "Basic negative test", &basic_negative_test);
	load_test(&testlist, "Basic jump test", &basic_jump_test);
	load_test(&testlist, "Null test", &null_test);
	load_test(&testlist, "Error test", &error_test);
	load_test(&testlist, "Error stop test", &error_stop_test);
	load_test(&testlist, "Error signe test", &error_signe_test);
	load_test(&testlist, "Intmin test", &intmin_test);
	load_test(&testlist, "Intmax test", &intmax_test);
	load_test(&testlist, "Small negative loop test", &small_negative_loop_test);
	load_test(&testlist, "Small positive loop test", &small_positive_loop_test);
	load_test(&testlist, "Medium negative loop test", &medium_negative_loop_test);
	load_test(&testlist, "Medium positive loop test", &medium_positive_loop_test);
	load_test(&testlist, "Large negative loop test", &large_negative_loop_test);
	load_test(&testlist, "Large positive loop test", &large_positive_loop_test);
	launch_tests(&testlist, res_test);
	del_test_lst(&testlist);
}
