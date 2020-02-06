/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:28:30 by nbethany          #+#    #+#             */
/*   Updated: 2019/01/15 18:42:39 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	size;
	char	*str;

	size = ft_strlen(s1) + 1;
	str = (char *)malloc(size);
	if (str == NULL)
		return (NULL);
	return ((char *)ft_memcpy(str, s1, size));
}
