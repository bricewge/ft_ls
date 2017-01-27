/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:59:46 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/29 09:54:23 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = (char*)malloc(sizeof(*dup) * ft_strlen(s1) + 1);
	return (dup ? ft_strcpy(dup, s1) : NULL);
}
