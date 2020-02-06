/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:40:34 by nbethany          #+#    #+#             */
/*   Updated: 2019/01/15 18:33:43 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*buffer;

	buffer = (char *)malloc(size + 1);
	if (buffer == NULL)
		return (NULL);
	return (ft_memset(buffer, '\0', size + 1));
}
