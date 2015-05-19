/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 13:03:32 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/02 19:18:45 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "computor.h"
#include <stdlib.h>

int		ft_get_pow(char *str, t_magic *magic)
{
	int		i;

	i = 1;
	if (str == NULL || ft_strlen(str) < 3 || str[0] != 'X' || str[1] != '^')
	{
		magic->error = 2;
		return (0);
	}
	else
	{
		while (str[++i])
		{
			if (ft_isdigit(str[i]) == 0)
			{
				magic->error = 2;
				return (0);
			}
		}
	}
	return (atoi(&str[2]));
}
