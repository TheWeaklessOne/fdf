/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 23:39:16 by nbethany          #+#    #+#             */
/*   Updated: 2019/01/15 18:47:12 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	new = NULL;
	i = 0;
	if (s)
	{
		new = (char *)malloc(ft_strlen(s) + 1);
		if (new)
		{
			while (s[i])
			{
				new[i] = (*f)(i, s[i]);
				i++;
			}
			new[i] = '\0';
		}
	}
	return (new);
}
