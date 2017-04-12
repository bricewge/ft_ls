/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:25:43 by bwaegene          #+#    #+#             */
/*   Updated: 2017/02/11 23:25:12 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

void		ft_atoi_launcher(int *res_test);
int			basic_positive_test(void);
int			basic_negative_test(void);
int			basic_jump_test(void);
int			null_test(void);
int			error_test(void);
int			error_stop_test(void);
int			error_signe_test(void);
int			intmin_test(void);
int			intmax_test(void);
int			small_negative_loop_test(void);
int			small_positive_loop_test(void);
int			medium_negative_loop_test(void);
int			medium_positive_loop_test(void);
int			large_negative_loop_test(void);
int			large_positive_loop_test(void);
void		ft_abs_launcher(int *res_test);
int			ft_abs_positive_test(void);
int			ft_abs_negative_test(void);
int			ft_abs_zero_test(void);
void		ft_nbrlen_launcher(int *res_test);
int			ft_nbrlen_positive_test(void);
int			ft_nbrlen_negative_test(void);
int			ft_nbrlen_zero_test(void);
#endif
