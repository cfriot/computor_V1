/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 11:27:31 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/02 19:26:07 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

typedef struct		s_pol
{
	float			coef;
	int				pow;
	struct s_pol	*next;
}					t_pol;

typedef struct		s_magic
{
	t_pol			*begin;
	int				error;
	int				flo;
}					t_magic;

void				ft_error(t_magic *magic);
void				ft_delete(t_magic *magic);
void				ft_resolve(t_magic *magic);
void				ft_display_reduced(t_magic *magic);
void				ft_display_reduced_float(t_magic *magic);
void				ft_clear_list(t_magic *magic);
void				ft_create_list(t_magic *magic,
						int tmp2, float tmp, int signe);
void				ft_add_list(t_magic *magic, int tmp2, float tmp, int signe);
void				ft_search_list(t_magic *magic, int tmp2,
						float tmp, int signe);
void				ft_update_magic_left(t_magic *magic, float tmp, int tmp2);
void				ft_update_magic_right(t_magic *magic, float tmp, int tmp2);
void				ft_parse_entry(char **tab, t_magic *magic);
void				ft_parse_entry_right(char **tab, t_magic *magic, int i);
float				ft_get_coef(char *str, t_magic *magic);
double				ft_sqrt(double nb);
int					ft_check_coef(char *str);
int					ft_tablen(char **tab);
int					ft_get_pow(char *str, t_magic *magic);
t_magic				ft_ini_magic(void);
#endif
