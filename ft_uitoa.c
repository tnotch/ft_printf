/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnotch <tnotch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:28:31 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/01/23 16:03:44 by tnotch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static int	ft_sizearray(unsigned int n)
{
	int i;

	i = 0;
	while ((n /= 10))
		i++;
	return (i);
}

char		*ft_uitoa(unsigned int n)
{
	unsigned long long int	num;
	char					*res;
	int						i;
	int						sign;

	i = 1;
	sign = 0;
	num = n;
	if (n < 0)
	{
		sign = 1;
		num = -num;
	}
	i = i + sign + ft_sizearray(n);
	if (!(res = (char*)malloc(i + 1)))
		return (NULL);
	res[i--] = '\0';
	while (i >= sign)
	{
		res[i--] = num % 10 + '0';
		num = num / 10;
	}
	if (sign != 0)
		res[0] = '-';
	return (res);
}
