/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bridg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:46:09 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/01 09:37:14 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_str_is_digit(char *str1, char *str2, char *str3)
{
	int i;

	i = 0;
	if (str3[0] == 'L')
		return (-1);
	while (str1[i])
	{
		if (ft_isdigit(str1[i]) == 0)
			return (-1);
		i++;
	}
	i = 0;
	while (str2[i])
	{
		if (ft_isdigit(str2[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int		ft_get_bridg_norme(t_env *e, int chr, int i)
{
	if (chr == e->leng_salle)
		return (-1);
	e->b[i].bridg_2 = e->s[chr].nb_salle;
	e->leng_bridg++;
	return (0);
}

int		ft_get_bridg(t_env *e, char *str, int i)
{
	char	**tab;
	t_bridg	*tmp;
	int		chr;

	tmp = e->b;
	tab = ft_strsplit(str, '-');
	if (ft_strlen_tab(tab) != 2 || tab[1][0] == '\n' ||
		ft_strcmp(tab[0], tab[1]) == 0)
		return (-1);
	if (!(e->b = (t_bridg *)malloc(sizeof(t_bridg) * (e->leng_bridg + 1))))
		exit(0);
	while (++i < e->leng_bridg)
		e->b[i] = tmp[i];
	chr = 0;
	while (chr < e->leng_salle && ft_strcmp(tab[0], e->s[chr].name))
		chr++;
	if (chr == e->leng_salle)
		return (-1);
	e->b[i].bridg_1 = e->s[chr].nb_salle;
	chr = 0;
	while (chr < e->leng_salle && ft_strcmp(tab[1], e->s[chr].name))
		chr++;
	if (ft_get_bridg_norme(e, chr, i) == -1)
		return (-1);
	return (0);
}
