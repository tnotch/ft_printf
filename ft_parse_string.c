/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnotch <tnotch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:15:13 by tnotch            #+#    #+#             */
/*   Updated: 2021/01/23 20:18:32 by tnotch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

t_var	ft_parse_flag(char **inp, t_var *vari)
{
	t_var	out;
	char	*v;

	v = *inp;
	vari->flagnull = 0;
	vari->flagmin = 0;
	vari->accur = -1;
	vari->width = 0;
	while (*v == '-' || *v == '+' || *v == '0' || *v == ' ' || *v == '#')
	{
		if (*v == '-')
			vari->flagmin = 1;
		if (*v == '+')
			v++;
		if (*v == '0')
			vari->flagnull = 1;
		if (*v == ' ')
			ft_putchar_fd(' ', 1);
		v++;
	}
	*inp = v;
	out = *vari;
	return (out);
}

void	ft_parse_width(char **inp, t_var *vari, va_list args)
{
	char	*var;
	char	width[11];
	int		size;

	var = *inp;
	size = 0;
	while (*var > 47 && *var < 58)
		width[size++] = *var++;
	width[size] = '\0';
	if (width[0] > 47 && width[0] < 58)
		vari->width = ft_atoi(width);
	if (*var == '*')
	{
		size = va_arg(args, int);
		if (size >= 0)
			vari->width = (size_t)size;
		else if (vari->flagnull == 1 || vari->flagnull == 0)
		{
			vari->flagmin = 1;
			vari->width = (size_t)(size * -1);
		}
		var++;
	}
	*inp = var;
}

void	ft_parse_accur(char **inp, t_var *vari, va_list args, int *flag)
{
	char	*var;
	char	accur[11];
	int		size;

	var = *inp;
	size = 0;
	vari->accur = 0;
	var++;
	if (*var == '*')
	{
		vari->accur = va_arg(args, int);
		var++;
		*flag = 1;
	}
	else if (*var > 47 && *var < 58)
	{
		while (*var > 47 && *var < 58)
			accur[size++] = *var++;
		accur[size] = '\0';
		if (accur[0] > 47 && accur[0] < 58)
			vari->accur = ft_atoi(accur);
	}
	*inp = var;
}

t_var	parse_p(char *var, va_list args)
{
	t_var	variable;
	int		size;
	int		flag;

	flag = 0;
	size = 0;
	variable = ft_parse_flag(&var, &variable);
	ft_parse_width(&var, &variable, args);
	if ((variable.flagnull == 1) && (variable.flagmin == 1))
		variable.flagnull = 0;
	if (*var == '.')
		ft_parse_accur(&var, &variable, args, &flag);
	size = variable.width;
	if ((variable.accur > 0))
		variable.flagnull = 0;
	if (variable.flagnull == 1 && variable.accur < 0 && variable.width > 0)
		variable.accur = variable.width;
	else if (variable.flagnull == 1 && variable.accur < 0 && size == 0)
		variable.accur = 1;
	if (variable.accur < 0 && variable.flagnull == 1 && flag == 1)
		variable.accur = variable.accur * -1;
	variable.type = *var;
	return (variable);
}
