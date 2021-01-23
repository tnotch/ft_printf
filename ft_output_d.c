/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnotch <tnotch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:31:30 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/01/23 19:43:25 by tnotch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

char	*ft_accur_d(char *input, int exponent, t_var **vari)
{
	int		i;
	t_var	*var;
	char	*result;
	char	*acc;

	i = 0;
	var = *vari;
	result = NULL;
	acc = NULL;
	if ((*input == '-') && (var->flagnull == 1))
		var->accur--;
	acc = malloc(sizeof(char) * (var->accur - exponent + 1));
	while (i < (var->accur - exponent))
		acc[i++] = '0';
	acc[i] = '\0';
	if (*input == '-')
	{
		result = ft_strdup("-");
		input++;
	}
	result = ft_strjoin(result, acc);
	free(acc);
	result = ft_strjoin(result, input);
	return (result);
}

char	*ft_width_d(char *input, size_t width, int flagmin)
{
	int		i;
	char	*res;
	char	*out;

	i = 0;
	out = ft_strdup(input);
	if ((res = malloc(sizeof(char) * (width - ft_strlen(input) + 1))))
	{
		while (width > ft_strlen(input))
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
			free(res);
		}
		return (out);
	}
	return (input);
}

char	*ft_output_d_p1(char *input, t_var *var)
{
	char	*result;
	char	*freed;
	int		exp;

	result = input;
	exp = ft_strlen(result);
	if (result[0] == '-')
		exp--;
	if (var->accur > 0 && var->accur > exp)
	{
		freed = ft_accur_d(result, exp, &var);
		free(result);
		result = ft_strdup(freed);
		free(freed);
	}
	if (var->accur == 0 && result[0] == '0')
	{
		free(result);
		result = ft_strdup("");
	}
	return (result);
}

int		ft_output_d(t_var variable, va_list args)
{
	int		res;
	char	*result;
	char	*freed;

	res = 0;
	result = ft_itoa(va_arg(args, int));
	result = ft_output_d_p1(result, &variable);
	if (variable.width && variable.width > ft_strlen(result))
	{
		freed = ft_width_d(result, variable.width, variable.flagmin);
		free(result);
		result = ft_strdup(freed);
		free(freed);
	}
	ft_putstr_fd(result, 1);
	res = ft_strlen(result);
	free(result);
	return (res);
}
