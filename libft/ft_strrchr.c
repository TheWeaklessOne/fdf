/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:30:38 by nbethany          #+#    #+#             */
/*   Updated: 2019/01/15 18:48:50 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	const char	*pos;
	const char	*cur;

	if ((unsigned char)c == '\0')
		return (ft_strchr(s, '\0'));
	pos = NULL;
	while ((cur = ft_strchr(s, c)) != NULL)
	{
		pos = cur;
		s++;
	}
	return ((char *)pos);
}
