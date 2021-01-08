/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnotch <tnotch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:15:13 by tnotch            #+#    #+#             */
/*   Updated: 2021/01/07 19:39:47 by tnotch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	parse_p(const char *var)
{
	t_var	variable;
	
	while(*var == '-' || *var == '+')
	{
		if(*var == '-')
			variable.flag = *var++;
		if(*var == '+')// обработка флага +
			var++;
	}
	while(*var > 47 && *var < 58)
	{
		
	}

int	main()
{
	const char *input = "----+++---d";

	parse_p(input);
}