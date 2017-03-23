/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_basic_error_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:44:02 by bwaegene          #+#    #+#             */
/*   Updated: 2017/02/11 22:36:15 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <string.h>

int		buserror_test(void)
{
	char *s;

	s = NULL;
	s = ft_strcpy("foobar", "trololol");
	if (s)
		return (0);
	else
		return (-1);
}
