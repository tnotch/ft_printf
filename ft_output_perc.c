/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_perc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 20:27:31 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/01/18 17:55:26 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_width_perc(int	width, int flag)
{
	int result;

	result = 0;
	while (width > 1)
	{
		if(flag == 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		width--;
		result++;	
	}
	return (result);
}

int	ft_output_perc(t_var variable)
{
	int		res;	

	res = 1;
	if (variable.width > 1 && variable.flagmin == 0)
		res = res + ft_width_perc(variable.width, variable.flagnull);
	ft_putchar_fd('%', 1);
	if (variable.width > 1 && variable.flagmin == 1)
		res = res + ft_width_perc(variable.width, 0);
	return (res);
}