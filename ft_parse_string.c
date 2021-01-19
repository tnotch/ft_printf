/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:15:13 by tnotch            #+#    #+#             */
/*   Updated: 2021/01/19 15:11:44 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

t_var	parse_p(const char *var, va_list args)
{
	t_var	variable;
	char	width[11];
	char	accur[11];
	int		size;
	int		flag;
	
	flag = 0;
	size = 0;
	variable.flagmin = 0;
	variable.accur = -1;
	variable.width = 0;
	variable.flagnull = 0;
	while(*var == '-' || *var == '+' || *var == '0' || *var == ' ' || *var == '#')
	{
		if(*var == '-')
			variable.flagmin = 1;
		if (*var =='+')
			var++;
		if (*var == '0')
			variable.flagnull = 1;
		if (*var == ' ')
			ft_putchar_fd(' ', 1);
		var++;
	}
	while(*var > 47 && *var < 58)
		width[size++] = *var++;
	width[size] = '\0';
	if (width[0] > 47 && width[0] < 58)
		variable.width = ft_atoi(width);
	if (*var == '*')
	{
		size = va_arg(args, int);
		if (size >= 0)
			variable.width = (size_t)size;
		else if (variable.flagnull == 1)
		{
			variable.flagmin = 1;
			variable.width = (size_t)(size * -1);
		}
		else if (variable.flagnull == 0)
		{
			variable.flagmin = 1;
			variable.width = (size_t)(size * -1);	
		}
		var++;
	}
	if ((variable.flagnull == 1) && (variable.flagmin == 1))
		variable.flagnull = 0;
	if (*var == '.')
	{
		variable.accur = 0;
		var++;
		size = 0;
		if (*var == '*')
		{
			variable.accur = va_arg(args, int);
			var++;
			flag = 1;
		}
		else
		{
			while(*var > 47 && *var < 58)
				accur[size++] = *var++;
			if (accur[0] > 47 && accur[0] < 58)
				variable.accur = ft_atoi(accur);
		}		
	}
	if ((variable.accur > 0))
		variable.flagnull = 0;
	if ((variable.flagnull == 1) && (variable.accur < 0) && (variable.width > 0))
		variable.accur = variable.width;
	else if ((variable.flagnull == 1) && (variable.accur < 0) &&variable.width == 0)
		variable.accur = 1;
	if (variable.accur < 0 && variable.flagnull == 1 && flag == 1)
		variable.accur = variable.accur * -1;
	variable.type = *var;
	return (variable);
}