/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_magic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 14:37:25 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/02 19:18:54 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"
#include <stdlib.h>

t_magic		ft_ini_magic(void)
{
	t_magic magic;

	magic.begin = NULL;
	magic.error = 0;
	magic.flo = 0;
	return (magic);
}
