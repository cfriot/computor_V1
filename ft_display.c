/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 18:17:18 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/02 19:18:25 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"
#include <stdio.h>

void	ft_display_line(float coef, int pow)
{
	if (coef < 0)
	{
		if (pow > 1)
			printf("- %.f * X^%d ", -coef, pow);
		else if (pow == 1)
			printf("- %.f * X ", -coef);
		else
			printf("- %.f ", -coef);
	}
	else
	{
		if (pow > 1)
			printf("+ %.f * X^%d ", coef, pow);
		else if (pow == 1)
			printf("+ %.f * X ", coef);
		else
			printf("+ %.f ", coef);
	}
}

void	ft_display_line_float(float coef, int pow)
{
	if (coef < 0)
	{
		if (pow > 1)
			printf("- %f * X^%d ", -coef, pow);
		else if (pow == 1)
			printf("- %f * X ", -coef);
		else
			printf("- %f ", -coef);
	}
	else
	{
		if (pow > 1)
			printf("+ %f * X^%d ", coef, pow);
		else if (pow == 1)
			printf("+ %f * X ", coef);
		else
			printf("+ %f ", coef);
	}
}

void	ft_display_reduced(t_magic *magic)
{
	t_pol	*cursor;

	cursor = magic->begin;
	if (magic->flo == 1)
		ft_display_reduced_float(magic);
	else if (cursor)
	{
		if (cursor->pow == 1)
			printf("%.f * X ", cursor->coef);
		else if (cursor->pow > 1)
			printf("%.f * X^%d ", cursor->coef, cursor->pow);
		else
			printf("%.f ", cursor->coef);
		while (cursor)
		{
			cursor = cursor->next;
			if (cursor)
				ft_display_line(cursor->coef, cursor->pow);
		}
		printf("= 0\n");
	}
	else
		printf("0 = 0\n");
}

void	ft_display_reduced_float(t_magic *magic)
{
	t_pol	*cursor;

	cursor = magic->begin;
	if (cursor)
	{
		if (cursor->pow == 1)
			printf("%f * X ", cursor->coef);
		else if (cursor->pow > 1)
			printf("%f * X^%d ", cursor->coef, cursor->pow);
		else
			printf("%f ", cursor->coef);
		while (cursor)
		{
			cursor = cursor->next;
			if (cursor)
				ft_display_line_float(cursor->coef, cursor->pow);
		}
		printf("= 0\n");
	}
	else
		printf("0 = 0\n");
}
