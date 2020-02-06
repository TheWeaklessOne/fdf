/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 04:38:30 by nbethany          #+#    #+#             */
/*   Updated: 2019/01/15 18:45:45 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dstcpy;
	unsigned char	*srccpy;

	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	if (srccpy > dstcpy)
		ft_memcpy(dstcpy, srccpy, len);
	else if (dstcpy > srccpy)
	{
		i = len;
		while (i)
		{
			dstcpy[i - 1] = srccpy[i - 1];
			i--;
		}
	}
	return (dstcpy);
}
