/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 23:22:03 by nbethany          #+#    #+#             */
/*   Updated: 2019/01/15 18:49:58 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
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
				new[i] = (*f)(s[i]);
				i++;
			}
			new[i] = '\0';
		}
	}
	return (new);
}
