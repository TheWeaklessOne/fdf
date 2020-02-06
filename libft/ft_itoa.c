/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 22:38:44 by nbethany          #+#    #+#             */
/*   Updated: 2019/01/15 18:18:28 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa(int n)
{
	char			*number;
	unsigned int	num;
	int				sign;
	int				len;

	len = ft_intlen(n);
	num = (n < 0 ? -n : n);
	sign = (n < 0 ? 1 : 0);
	number = (char *)malloc(sizeof(*number) * len + 1);
	if (!number)
		return (NULL);
	number[len--] = '\0';
	while (len >= 0)
	{
		number[len] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	if (sign)
		number[0] = '-';
	return (number);
}
