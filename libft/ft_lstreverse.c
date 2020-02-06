/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:08:28 by nbethany          #+#    #+#             */
/*   Updated: 2019/04/12 19:12:08 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstreverse(t_list *alst)
{
	t_list			*node;
	t_list			*reversed;
	t_list			*tmp;

	if (!(alst) || !(alst->next))
		return (alst);
	node = alst->next;
	reversed = alst;
	reversed->next = NULL;
	while (node)
	{
		tmp = node;
		node = node->next;
		tmp->next = reversed;
		reversed = tmp;
	}
	return (reversed);
}
