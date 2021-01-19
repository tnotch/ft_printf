/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:31:30 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/01/19 13:34:12 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

char	*ft_accur_d(char *input, int exponent, t_var vari)
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

char	*ft_width_d(char *input, size_t width, int flagmin)
{
	int	i;
	char *res;
	char *out;

	i = 0;
	out = ft_strdup(input);
	if ((res = malloc(sizeof(char) * (width - ft_strlen(input) + 1))))
	{
		while(width > ft_strlen(input))
		{
			res[i++] = ' ';
			width--;
		}
		res[i] = '\0';
		if (flagmin == 0)
			out = ft_strjoin(res, input);
		else if (flagmin == 1)
		{
			out = ft_strjoin(out, res);
			free (res);
		}
		return (out);
	}
	return (input);
}

int		ft_output_d(t_var	variable, va_list args)
{
	int		res;
	int		exp; //порядок числа
	char	*result;
	char	*freed;
	char	*var;
	
	res = 0;
	var = ft_itoa(va_arg(args, int));
	result = ft_strdup(var);//NB - free
	free(var);
	exp = ft_strlen(result);
	if (result[0] == '-')
		exp--;
	if (variable.accur > 0 && variable.accur > exp)
	{
		
		freed = ft_accur_d(result, exp, variable);
		free(result);
		result = ft_strdup(freed);
		free(freed);
	}
	if (variable.accur == 0 && variable.flagnull == 0 && result[0] == '0')
	{
		free(result);
		result = ft_strdup("");
	}
	if (variable.accur == 0 && variable.flagnull == 1 && result[0] == '0')
	{
		free(result);
		result = ft_strdup("");
	}
	if (variable.width && variable.width > ft_strlen(result))
	{
		var = ft_width_d(result, variable.width, variable.flagmin);
		free(result);
		result = ft_strdup(var);
		free(var);
	}
	ft_putstr_fd(result, 1);
	res = ft_strlen(result);
	free(result);
	return (res);
}