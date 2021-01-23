/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnotch <tnotch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:22:36 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/01/23 16:06:30 by tnotch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct			s_var
{
	char				type;
	int					flagmin;
	int					flagnull;
	size_t				width;
	int					accur;
}						t_var;

int						ft_printf(const char *format, ...);
t_var					parse_p(char *var, va_list args);
int						ft_output_d(t_var	variable, va_list args);
int						ft_output_c(t_var variable, va_list args);
int						ft_output_s(t_var	variable, va_list args);
int						ft_output_p(t_var variable, va_list args);
int						ft_output_u(t_var	variable, va_list args);
int						ft_output_x(t_var variable, va_list args);
int						ft_output_perc(t_var variable);
char					*ft_uitoa(unsigned int n);

#endif
