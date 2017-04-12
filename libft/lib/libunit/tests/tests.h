/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:25:43 by bwaegene          #+#    #+#             */
/*   Updated: 2017/02/12 18:28:30 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include "libunit.h"

void		m_framework_launcher(int *res_test);
int			ok_test(void);
int			ko_test(void);
int			segfault_test(void);
int			buserror_test(void);
int			timeout_test(void);
int			free_abort_test(void);
#endif
