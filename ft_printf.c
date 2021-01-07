/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:22:09 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/01/07 11:46:31 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_whattype(char *input, va_list args)
{
	if(*input == 'd')
	{
		return (ft_itoa(va_arg(args, int)));
	}
	return ("error");
}

int	printf_output(char *input, va_list args)
{
	int	result;
	char *start;

	result = 0;
	start = ft_strdup(input);
	while(1)
	{
		if(*input == '%')
		{
			input++;
			ft_putstr_fd(ft_whattype(input, args), 1);
			input++;
		}
		if(!*input)
			break ;
		ft_putchar_fd(*input, 1);
		input++;
	}
	free (start);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	char		*safe;
	va_list		args;
	int			char_num;

	va_start(args, format);
	safe = ft_strdup(format);
	char_num = printf_output(safe, args);
	va_end(args);
	free (safe);
	return (char_num);
}





int	main(void)
{
	int i = 5;

	ft_printf("it is %d\n", i);
}