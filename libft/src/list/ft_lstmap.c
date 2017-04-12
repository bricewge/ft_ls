/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 17:40:25 by bwaegene          #+#    #+#             */
/*   Updated: 2016/12/29 05:04:26 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*result;
	t_list	*previous;

	result = NULL;
	if (lst)
	{
		new = ft_lstnew(f(lst)->content, f(lst)->content_size);
		result = new;
		previous = new;
		lst = lst->next;
		while (lst)
		{
			if ((new = (t_list *)malloc(sizeof(*result))))
			{
				new->content = f(lst)->content;
				new->content_size = f(lst)->content_size;
				previous->next = new;
				previous = new;
			}
			lst = lst->next;
		}
	}
	return (result);
}
