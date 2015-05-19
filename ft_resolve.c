/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 14:19:35 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/02 19:19:08 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "computor.h"

void	ft_resolve_zero(t_magic *magic)
{
	printf("Polynomial degree: 0\n");
	if (magic->begin)
		printf("No solution, the equation is false\n");
	else
		printf("All the real are solution\n");
}

void	ft_resolve_one(t_magic *magic)
{
	t_pol	*cursor;
	float	value;

	cursor = magic->begin;
	value = 0;
	printf("Polynomial degree: 1\n");
	while (cursor)
	{
		if (cursor->pow == 0)
			value = -cursor->coef;
		cursor = cursor->next;
	}
	cursor = magic->begin;
	while (cursor)
	{
		if (cursor->pow == 1)
			value = value / cursor->coef;
		cursor = cursor->next;
	}
	printf("There is only one solution, which is : X = %f\n", value);
}

void	ft_resolve_two_bis(float a, float b, float c)
{
	float	delta;

	delta = b * b - (4 * a * c);
	printf("Determinant is: %f\n", delta);
	if (delta == 0)
	{
		printf("Delta is null, there is only one solution : ");
		-b / 2 * a == 0 ? printf("0\n") : printf("%f\n", -b / (2 * a));
	}
	else if (delta > 0)
	{
		printf("Delta is strictly greater than 0, there is two solution:\n");
		printf("Sol 1: %f", (-b + ft_sqrt(delta)) / (2 * a));
		printf("       Sol 2: %f\n", (-b - ft_sqrt(delta)) / (2 * a));
	}
	else if (delta < 0)
	{
		printf("Delta is strictly lower than 0, there is no solution in R\n");
		printf("But there is two solution in I:\n");
		printf("Sol 1: (%f + %fi) / %f", -b, ft_sqrt(delta), 2 * a);
		printf("       Sol 2: (%f - %fi) / %f\n", -b, ft_sqrt(delta), 2 * a);
	}
}

void	ft_resolve_two(t_magic *magic)
{
	t_pol	*cursor;
	float	a;
	float	b;
	float	c;

	printf("Polynomial degree: 2\n");
	a = 0;
	b = 0;
	c = 0;
	cursor = magic->begin;
	while (cursor)
	{
		if (cursor->pow == 2)
			a = cursor->coef;
		if (cursor->pow == 1)
			b = cursor->coef;
		if (cursor->pow == 0)
			c = cursor->coef;
		cursor = cursor->next;
	}
	ft_resolve_two_bis(a, b, c);
}

void	ft_resolve(t_magic *magic)
{
	int		pow;
	t_pol	*cursor;

	pow = 0;
	cursor = magic->begin;
	while (cursor)
	{
		if (cursor->pow > pow)
			pow = cursor->pow;
		cursor = cursor->next;
	}
	if (pow > 2)
	{
		printf("The polynomial degree is strictly greater than 2, ");
		printf("I can't solve\n");
	}
	else if (pow == 0)
		ft_resolve_zero(magic);
	else if (pow == 1)
		ft_resolve_one(magic);
	else
		ft_resolve_two(magic);
}
