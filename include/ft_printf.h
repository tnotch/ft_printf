/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:22:36 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/01/18 14:53:45 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

#define FT_PRINTF_H


#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>



typedef struct			s_var
{
	char				type;
	int					flagmin;
	int					flagnull;
	size_t				width;
	int					accur;
}						t_var;

int						ft_printf(const char *format, ...);
t_var					parse_p(const char *var, va_list args);
int						ft_output_d(t_var	variable, va_list args);
int						ft_output_c(t_var variable, va_list args);
int						ft_output_s(t_var	variable, va_list args);
int						ft_output_p(t_var variable, va_list args);
int						ft_output_u(t_var	variable, va_list args);
int						ft_output_x(t_var variable, va_list args);
int						ft_output_perc(t_var variable);

#endif