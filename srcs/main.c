/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:20:07 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/02 13:24:42 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_strlen_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

int		ft_check_patch(t_env *e)
{
	int	i;
	int	j;
	int	y;

	y = 0;
	j = -1;
	i = -1;
	while (++i < e->leng_salle && e->s[i].start != 1)
		;
	if (e->s[i].size_bridg == 0)
	{
		ft_putstr("ERROR");
		return (-1);
	}
	while (++j < e->s[i].size_bridg)
	{
		y = -1;
		while (++y < e->leng_salle)
		{
			if (e->s[i].bridg[j] == e->s[y].nb_salle && e->s[y].poid != 255)
				return (0);
		}
	}
	ft_putstr("ERROR");
	return (-1);
}

int		main(void)
{
	t_env	e;
	int		i;

	i = 0;
	e.salle = 0;
	if (ft_parsing(&e) == -1)
		return (-1);
	if (ft_check_patch(&e) == -1)
		return (-1);
	ft_resolv(&e);
	return (0);
}
