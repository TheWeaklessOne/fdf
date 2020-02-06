/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 20:50:07 by nbethany          #+#    #+#             */
/*   Updated: 2019/01/15 18:38:02 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*scpy;
	size_t	i;

	scpy = (char *)malloc(sizeof(*scpy) * (len + 1));
	i = 0;
	if (!scpy || !s)
		return (NULL);
	while (len--)
	{
		scpy[i] = s[start + i];
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}
