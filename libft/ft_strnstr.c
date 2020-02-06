/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:09:08 by nbethany          #+#    #+#             */
/*   Updated: 2019/01/15 19:57:51 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *hstck, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;

	if (!ndl[0])
		return ((char *)hstck);
	i = 0;
	while (hstck[i] && i < len)
	{
		if (hstck[i] == ndl[0])
		{
			j = 1;
			while (ndl[j] && hstck[j + i] == ndl[j] && (i + j < len))
				j++;
			if (ndl[j] == '\0')
				return ((char *)&hstck[i]);
		}
		i++;
	}
	return (NULL);
}
