/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:22:36 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/01/05 16:17:27 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

#define FT_PRINTF_H


#include "../libft/libft.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct			s_var
{
	char				type;
	char				flag;
	int					width;
	char				accur;
	struct s_var		*next;	
}						t_var;


#endif