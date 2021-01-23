/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnotch <tnotch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:10:30 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/01/23 15:50:59 by tnotch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_width_c(int width)
{
	int result;

	result = 0;
	while (width > 1)
	{
		ft_putchar_fd(' ', 1);
		width--;
		result++;
	}
	return (result);
}

int	ft_output_c(t_var variable, va_list args)
{
	int		res;
	char	var;

	res = 1;
	var = va_arg(args, int);
	if (variable.width > 1 && variable.flagmin == 0)
		res = res + ft_width_c(variable.width);
	ft_putchar_fd(var, 1);
	if (variable.width > 1 && variable.flagmin == 1)
		res = res + ft_width_c(variable.width);
	return (res);
}
