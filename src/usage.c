/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:40:58 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/30 00:22:15 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	usage(char *options)
{
	ft_putstr_fd("usage: ft_ls [-", 2);
	ft_putstr_fd(options, 2);
	ft_putendl_fd("] [file ...]", 2);
	exit(1);
}
