/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:05:52 by nbethany          #+#    #+#             */
/*   Updated: 2019/01/15 18:25:58 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcapitalize(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	str = ft_strlowcase(str);
	while (str[i])
	{
		if ((i == 0 || ft_isspace(str[i - 1]) || str[i - 1] == '+' ||
					str[i - 1] == '-') && (ft_islower(str[i])))
			str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
