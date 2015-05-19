/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coef.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 13:11:36 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/02 19:18:35 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "computor.h"
#include <stdlib.h>
#include <stdio.h>

float	ft_get_coef(char *str, t_magic *magic)
{
	float	coef;
	float	b;
	char	**tab;
	int		pow;

	pow = -1;
	coef = 0;
	if (ft_check_coef(str) == 1)
	{
		tab = ft_strsplit(str, '.');
		(ft_tablen(tab) == 1) ? coef = atoi(tab[0]) : ft_putstr("");
		if (ft_tablen(tab) == 2)
		{
			magic->flo = 1;
			b = atoi(tab[1]);
			while (++pow < ft_strlen(tab[1]))
				b = (float)b / 10;
			coef = atoi(tab[0]) + b;
		}
		else if (ft_tablen(tab) != 1)
			magic->error = 1;
	}
	else
		magic->error = 1;
	return (coef);
}

int		ft_check_coef(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] != '.' && ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
