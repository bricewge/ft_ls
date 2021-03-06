/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:03:59 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/29 05:52:56 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb == 1)
		return (1);
	else if (nb <= 0)
		return (0);
	while (i * i != nb && i < nb)
		i++;
	if (i == nb)
		return (0);
	return (i);
}
