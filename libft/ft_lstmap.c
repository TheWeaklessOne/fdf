/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:22:08 by nbethany          #+#    #+#             */
/*   Updated: 2019/01/15 18:07:04 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*head;

	if (!lst)
		return (NULL);
	head = f(lst);
	tmp = head;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = (*f)(lst);
		if (!(tmp->next))
			return (NULL);
		tmp = tmp->next;
	}
	return (head);
}
