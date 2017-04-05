/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bridg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:46:09 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/05 19:46:12 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_get_bridg(t_env *e, char *str)
{
	char	**tab;
	t_bridg	*tmp;
	int		i;

	i = -1;
	tmp = e->b;
	tab = ft_strsplit(str, '-');
	if (ft_strlen_tab(tab) != 2 || tab[1][0] == '\n')
		return (-1);
	e->b = (t_bridg *)malloc(sizeof(t_bridg) * (e->leng_bridg + 1));
	while (++i < e->leng_bridg)
		e->b[i] = tmp[i];
	e->b[i].bridg_1 = ft_atoi(tab[0]);
	e->b[i].bridg_2 = ft_atoi(tab[1]);
	e->leng_bridg++;
	return (0);
}
