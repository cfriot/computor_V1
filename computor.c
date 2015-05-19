/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorV1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 11:31:06 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/02 19:27:32 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "computor.h"
#include <stdio.h>

int		ft_get_thing(char **tab, t_magic *magic, int i, int signe)
{
	int		tmp2;
	float	tmp;

	tmp = ft_get_coef(tab[i], magic);
	if (tab[i + 1])
	{
		if (tab[i + 1][0] == '*' && ft_strlen(tab[i + 1]) == 1)
			i = i + 2;
		tmp2 = ft_get_pow(tab[i], magic);
		ft_search_list(magic, tmp2, tmp, signe);
	}
	return (i);
}

void	ft_parse_entry(char **tab, t_magic *magic)
{
	int		i;
	int		signe;

	signe = 1;
	i = 0;
	while (tab[i] && tab[i][0] != '=' && magic->error == 0)
	{
		i = ft_get_thing(tab, magic, i, signe);
		i++;
		if (tab[i] && ft_strlen(tab[i]) == 1 &&
				(tab[i][0] == '+' || tab[i][0] == '-')
				&& tab[i + 1] && tab[i + 1][0] != '=')
		{
			signe = 1;
			if (tab[i][0] == '-')
				signe = -1;
			i++;
		}
	}
	if (tab[i] && ft_strlen(tab[i]) == 1 && tab[i][0] == '=')
		ft_parse_entry_right(tab, magic, i + 1);
	else if (magic->error == 0)
		magic->error = 3;
}

void	ft_parse_entry_right(char **tab, t_magic *magic, int i)
{
	int		signe;

	signe = -1;
	if (tab[i])
	{
		while (tab[i] && magic->error == 0)
		{
			i = ft_get_thing(tab, magic, i, signe);
			i++;
			if (tab[i] && ft_strlen(tab[i]) == 1 &&
					(tab[i][0] == '+' || tab[i][0] == '-') && tab[i + 1])
			{
				signe = -1;
				if (tab[i][0] == '-')
					signe = 1;
				i++;
			}
			else if (i != ft_tablen(tab))
				magic->error = 4;
		}
	}
}

int		main(int ac, char **av)
{
	char		**tab;
	t_magic		magic;

	if (ac != 2)
		printf("You must enter an equation\n");
	else
	{
		magic = ft_ini_magic();
		tab = ft_strsplit(av[1], ' ');
		if (tab != NULL)
		{
			ft_parse_entry(tab, &magic);
			if (magic.error == 0)
			{
				ft_clear_list(&magic);
				printf("Reduced form: ");
				ft_display_reduced(&magic);
				ft_resolve(&magic);
			}
			else
				ft_error(&magic);
			ft_delete(&magic);
		}
	}
	return (0);
}
