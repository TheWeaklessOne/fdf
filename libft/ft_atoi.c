/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 02:41:09 by nbethany          #+#    #+#             */
/*   Updated: 2019/01/15 18:02:29 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t				i;
	unsigned long long	result;
	int					sign;

	result = 0;
	sign = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
	{
		if (str[i] == '-')
			sign = 1;
		else if (str[i] != '+')
			return (0);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (result > 9223372036854775807)
			return (sign == 1 ? 0 : -1);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (sign == 1 ? -result : result);
}
