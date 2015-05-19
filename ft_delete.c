/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 17:04:48 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/02 19:18:15 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"
#include <stdlib.h>

void	ft_delete(t_magic *magic)
{
	t_pol	*cursor;
	t_pol	*tmp;

	cursor = magic->begin;
	tmp = NULL;
	while (cursor)
	{
		tmp = cursor;
		cursor = cursor->next;
		free(tmp);
	}
}
