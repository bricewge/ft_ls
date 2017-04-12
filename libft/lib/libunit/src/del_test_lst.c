/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_test_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 13:18:56 by starrit           #+#    #+#             */
/*   Updated: 2017/02/12 15:54:11 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	del_test_lst(t_test **base)
{
	t_test	*tmp;

	while ((*base)->next)
	{
		tmp = (*base)->next;
		ft_strdel(&(*base)->name);
		free(*base);
		*base = NULL;
		*base = tmp;
		tmp = NULL;
	}
	ft_strdel(&(*base)->name);
	free(*base);
	base = NULL;
}
