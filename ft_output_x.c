/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:32:12 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/01/19 15:26:59 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

char	*ft_deci_to_hexa_x(int	exponent, unsigned int number, char type)
{
	char		*res;
	char		*hexa;

	if (number == 0)
		return (ft_strdup("0"));
	if (type == 'x')
		hexa = "0123456789abcdef";
	else if (type == 'X')
		hexa = "0123456789ABCDEF";	
	res = malloc(sizeof(char) * (exponent));
	res[exponent] = '\0';
	exponent--;
	while(exponent > 0 || number != 0)
	{
		res[exponent--] = hexa[number % 16];
		number /= 16;
	}
	res[exponent] = hexa[number % 16];
	return (res);
}

char	*ft_accur_x(char *input, int exponent, t_var vari)
{
	int		i;
	char	*result;
	char	*acc;

	i = 0;
	result = NULL;
	acc = NULL;
	if ((*input == '-') && (vari.flagnull == 1))
		vari.accur--;
	acc = malloc(sizeof(char) * (vari.accur - exponent + 1));
	while (i < (vari.accur - exponent))
		acc[i++] = '0';
	acc[i] = '\0';
	if (*input == '-')
	{
		result = ft_strdup("-");// NB - free
		input++;
	}
	result = ft_strjoin(result, acc);
	free(acc);
	result = ft_strjoin(result, input);
	return (result);
}


char	*ft_width_x(char *input, int width, int flag)
{
	int		exp;
	int		i;
	char 	*result;
	char	*out;
	
	i = 0; 
	out = NULL;
	exp = ft_strlen(input);
	result = malloc(sizeof(char) * (width - exp + 1));
	while ((width - exp) > i)
		result[i++] = ' ';
	result[i] = '\0';
	if (flag == 1)
	{
		out = ft_strjoin(input, result);
		free(result);
	}
	else
	{
		out = ft_strjoin(result, input);
		free(input);
	}
	return (out);
}

int	ft_output_x(t_var variable, va_list args)
{
	int				exp;
	unsigned int	res;
	unsigned int	save;
	char			*hexa;
	
	exp = 0;
	res = va_arg(args, unsigned int);
	save = res;
	hexa = NULL;
	if (save == 0)
		exp++;
	while (save != 0)
	{
		save /= 16;
		exp++;
	}
	hexa = ft_deci_to_hexa_x(exp, res, variable.type);
	if (variable.accur > exp)
		hexa = ft_accur_x(hexa, exp, variable);
	if (variable.accur == 0 && hexa[0] == '0')
	{
		free(hexa);
		hexa = ft_strdup("");
	}
	if (variable.width > ft_strlen(hexa))
		hexa = ft_width_x(hexa, variable.width, variable.flagmin);
	ft_putstr_fd(hexa, 1);
	exp = ft_strlen(hexa);
	free(hexa);
	return (exp);
}