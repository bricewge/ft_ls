/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:55:36 by bwaegene          #+#    #+#             */
/*   Updated: 2017/02/11 23:52:16 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void		load_test(t_test **testlist, char *name, int (*f)(void))
{
	t_test *tmp;

	tmp = NULL;
	if (!name || !f)
		return ;
	if (!(*testlist))
		*testlist = create_test_lst();
	else
		add_test_lst(*testlist);
	tmp = *testlist;
	while (tmp->next)
		tmp = tmp->next;
	tmp->name = ft_strdup(name);
	tmp->f = f;
}
