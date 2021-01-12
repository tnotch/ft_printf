/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:15:13 by tnotch            #+#    #+#             */
/*   Updated: 2021/01/11 21:09:36 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_var	parse_p(const char *var)
{
	t_var	variable;
	char	width[11];
	char	accur[11];
	int		size;
	
	size = 0;
	while(*var == '-' || *var == '+')
	{
		if(*var == '-')
			variable.flag = *var++;
		if(*var == '+')// обработка флага +
			var++;
	}
	while(*var > 47 && *var < 58)
		width[size++] = *var++;
	width[size] = '\0';
	if (width[0] > 47 && width[0] < 58)
		variable.width = ft_atoi(width);
	if (*var == '.')
	{
		var++;
		size = 0;
		while(*var > 47 && *var < 58)
			accur[size++] = *var++;
		if (accur[0] > 47 && accur[0] < 58)
			variable.accur = ft_atoi(accur);
	}
	variable.type = *var;
	return (variable);
	printf("flag - %c\nwidth - %d\naccur - %d\ntype - %c", variable.flag, variable.width, variable.accur, variable.type);
}

/*int	main()
{
	const char *input = "----+++---123.78d";

	parse_p(input);
}*/