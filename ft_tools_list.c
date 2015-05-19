/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 15:41:55 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/02 19:19:31 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_clear_list2(t_magic *magic)
{
	t_pol	*cursor;
	t_pol	*previous;
	t_pol	*tmp;

	previous = magic->begin;
	cursor = NULL;
	if (previous)
		cursor = previous->next;
	while (cursor)
	{
		if (cursor->coef == 0)
		{
			previous->next = cursor->next;
			tmp = cursor;
			cursor = cursor->next;
			free(tmp);
		}
		if (cursor)
		{
			previous = previous->next;
			cursor = cursor->next;
		}
	}
}

void	ft_clear_list(t_magic *magic)
{
	t_pol	*cursor;
	t_pol	*tmp;

	cursor = magic->begin;
	tmp = NULL;
	while (magic->begin && magic->begin->coef == 0)
		magic->begin = magic->begin->next;
	while (cursor && cursor != magic->begin)
	{
		tmp = cursor;
		cursor = cursor->next;
		free(tmp);
	}
	ft_clear_list2(magic);
}

void	ft_create_list(t_magic *magic, int tmp2, float tmp, int signe)
{
	t_pol	*begin;

	begin = (t_pol *)malloc(sizeof(t_pol));
	if (begin)
	{
		begin->coef = signe * tmp;
		begin->pow = tmp2;
		begin->next = NULL;
		magic->begin = begin;
	}
}

void	ft_add_list(t_magic *magic, int tmp2, float tmp, int signe)
{
	t_pol	*cursor2;
	t_pol	*cursor;

	cursor = magic->begin;
	cursor2 = (t_pol *)malloc(sizeof(t_pol));
	if (tmp)
	{
		cursor2->coef = signe * tmp;
		cursor2->pow = tmp2;
		cursor2->next = NULL;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = cursor2;
	}
}

void	ft_search_list(t_magic *magic, int tmp2, float tmp, int signe)
{
	t_pol	*cursor;

	cursor = magic->begin;
	while (cursor)
	{
		if (tmp2 == cursor->pow)
		{
			cursor->coef += tmp * signe;
			return ;
		}
		cursor = cursor->next;
	}
	if (magic->begin == NULL)
		ft_create_list(magic, tmp2, tmp, signe);
	else if (cursor == NULL)
		ft_add_list(magic, tmp2, tmp, signe);
}
