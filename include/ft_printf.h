/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:22:36 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/01/11 21:10:20 by kirilltruha      ###   ########.fr       */
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
	char				flag;
	int					width;
	int					accur;
}						t_var;

t_var					parse_p(const char *var);

#endif