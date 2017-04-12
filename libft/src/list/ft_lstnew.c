/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:04:59 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/28 19:22:43 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (new)
	{
		if (!content)
		{
			new->content = NULL;
			new->content_size = 0;
		}
		else
		{
			new->content = malloc(sizeof(*content) * content_size);
			if (new->content)
			{
				ft_memcpy(new->content, content, content_size);
				new->content_size = content_size;
			}
		}
		new->next = NULL;
	}
	return (new);
}
