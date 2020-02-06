/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 23:58:14 by nbethany          #+#    #+#             */
/*   Updated: 2019/01/15 20:17:11 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void *cpy;
	void *pcpy;

	cpy = ft_memchr(src, c, n);
	pcpy = NULL;
	if (cpy)
	{
		pcpy = ft_memcpy(dst, src, cpy - src + 1);
		pcpy += cpy - src + 1;
		return (pcpy);
	}
	ft_memcpy(dst, src, n);
	return (NULL);
}
