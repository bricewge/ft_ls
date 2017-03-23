/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_basic_error_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:44:02 by bwaegene          #+#    #+#             */
/*   Updated: 2017/02/11 19:52:06 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <string.h>

int		ko_test(void)
{
	if (ft_strlen("trololol") == strlen("trololo"))
		return (0);
	else
		return (-1);
}
