/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_test_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 13:16:34 by starrit           #+#    #+#             */
/*   Updated: 2017/02/11 18:01:20 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	add_test_lst(t_test *base)
{
	t_test	*new;
	t_test	*tmp;

	new = NULL;
	tmp = base;
	new = create_test_lst();
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
