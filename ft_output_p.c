/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnotch <tnotch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:26:48 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/01/23 15:53:05 by tnotch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

char	*ft_deci_to_hexa(int exponent, long long number)
{
	char		*res;
	char		*hexa;

	hexa = "0123456789abcdef";
	if (number == 0)
		return (ft_strdup("0"));
	res = malloc(sizeof(char) * (exponent));
	res[exponent] = '\0';
	exponent--;
	while (exponent > 0 || number != 0)
	{
		res[exponent--] = hexa[number % 16];
		number /= 16;
	}
	res[exponent] = hexa[number % 16];
	return (res);
}

char	*ft_width_p(char *input, int width, int flag)
{
	int		exp;
	int		i;
	char	*result;
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

int		ft_output_p(t_var variable, va_list args)
{
	int			exp;
	long long	res;
	long long	save;
	char		*result;
	char		*hexa;

	exp = 0;
	result = ft_strdup("0x");
	res = (long long)va_arg(args, void *);
	save = res;
	while (save != 0)
	{
		save /= 16;
		exp++;
	}
	hexa = ft_deci_to_hexa(exp, res);
	result = ft_strjoin(result, hexa);
	free(hexa);
	if (variable.width > ft_strlen(result))
		result = ft_width_p(result, variable.width, variable.flagmin);
	ft_putstr_fd(result, 1);
	exp = ft_strlen(result);
	free(result);
	return (exp);
}
