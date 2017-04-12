/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:57:00 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/21 15:16:05 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libunit.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

void	ft_putendl(char const *s)
{
	if (s)
	{
		ft_putstr((char *)s);
		ft_putchar('\n');
	}
}

void	ft_putnbr(int nb)
{
	char	*intmin;

	intmin = "-2147483648";
	if (nb == -2147483648)
	{
		while (*intmin)
			ft_putchar(*intmin++);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}
