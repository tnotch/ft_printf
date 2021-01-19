/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:24:07 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/01/19 13:11:00 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

char	*ft_width_s(char *input, int space, int flag, size_t *res)
{
	int		i;
	char	*gap;
	char	*result;
	
	i = 0;
	gap = malloc(sizeof(char) * (space + 1));
	while(space)
	{
		gap[i++] = ' ';
		space--;
		*res = *res + 1;
	}
	gap[i] = '\0';
	if (flag == 1)
	{
		result = ft_strdup(input);
		result = ft_strjoin(result, gap);
		free (gap);
	}
	else
		result = ft_strjoin(gap, input);
	return (result);
}

char	*ft_accur_s(char *input, int accur)
{
	int		i;
	char	*result;

	i = 0;
	if (accur == 0)
		return (ft_strdup(""));
	result = malloc(sizeof(char) * (accur + 1));
	result[accur] = '\0';
	while (i < accur)
	{
		result[i] = input[i];
		i++;
	}
	return (result);
	
}

int	ft_output_s(t_var	variable, va_list args)
{
	size_t		res;
	int			flag;
	char		*result;

	res = 0;
	flag = 0;
	if (!(result = va_arg(args, char *)))
	{
		flag = 1;
		result = ft_strdup("(null)");
	}
	if (variable.accur >= 0)
	{
		result = ft_accur_s(result, variable.accur);
	}
	res =  ft_strlen(result);
	if (variable.width > res)
		result = ft_width_s(result, (variable.width - res), variable.flagmin, &res);
	ft_putstr_fd(result, 1);
	if (flag == 1 || variable.accur >= 0 || variable.width > res)
		free(result);
	return (res);
}