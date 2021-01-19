/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:22:09 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/01/19 16:26:36 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int ft_whattype(char *input, va_list args)
{
	t_var	variable;
	int		result;
	
	result = 0;
	variable = parse_p(input, args);
	if(variable.type == 'd')
		result = ft_output_d(variable, args);
	if(variable.type == 'c')
		result = ft_output_c(variable, args);
	if(variable.type == 's')
		result = ft_output_s(variable, args);
	if(variable.type == 'p')
		result = ft_output_p(variable, args);
	if(variable.type == 'i')
		result = ft_output_d(variable, args);
	if(variable.type == 'u')
		result = ft_output_u(variable, args);
	if(variable.type == 'x'|| variable.type == 'X')
		result = ft_output_x(variable, args);
	if(variable.type == '%')
		result = ft_output_perc(variable);
	return (result);
}

char	*ft_pass_var(char *input)
{
	while(*input == '-' || *input == '0' || *input == '+' || *input == '#' || *input == ' ')
		input++;
	while((*input > 47 && *input < 58) || *input == '*')
		input++;
	if (*input == '.')
		input++;
	while ((*input > 47 && *input < 58) || *input == '*')
		input++;
	input++;
	return (input);
}

int	printf_output(char *input, va_list args)
{
	int	result;
	char *start;

	result = 0;
	start = ft_strdup(input);
	while(1)
	{
		while(*input == '%')
		{
			input++;
			result = result + ft_whattype(input, args);
			input = ft_pass_var(input);
		}
		if(!*input)
			break ;
		ft_putchar_fd(*input, 1);
		result++;
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
