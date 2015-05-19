/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 17:40:14 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/02 19:20:07 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "computor.h"

void	ft_error(t_magic *magic)
{
	if (magic->error != 0)
		printf("There is an error of format\n");
}
