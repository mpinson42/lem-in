/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_poid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:03:12 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/05 14:03:20 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int ft_check(int z)
{
	int i;
	int bol;
	static int leng = 1;
	static int tab[255];

	bol = 0;
	i = 0;
	tab[0] = 0;
	while (i < leng)
	{
		if (tab[i] == z)
			return (0);
		i++;
	}
	tab[leng] = z;
	leng++;
	return (1);
}


void edit_poid2(t_env *e, t_edit *ed)
{
	ed->i = -1;
	while (++ed->i < e->leng_salle)
	{
		if (e->s[ed->i].poid == ed->a)
		{
			ed->z = -1;
			while (++ed->z < e->leng_salle)
			{
				ed->y = -1;
				while (++ed->y < e->s[ed->z].size_bridg)
				{
					if (e->s[ed->z].bridg[ed->y] == e->s[ed->i].nb_salle && ed->a < e->s[ed->z].poid && ft_check(ed->z))
					{
						e->poid_max = ed->a + 1;
						e->s[ed->z].poid = ed->a + 1;
					}
				}
			}
		}
	}
}

void edit_edit_poid(t_edit *ed)
{
	ed->bol = 0;
	ed->i = 0;
	ed->a = -1;
}

void edit_poid(t_env *e)
{
	t_edit ed;

	edit_edit_poid(&ed);
	while(e->s[ed.i].end != 1)
		ed.i++;
	e->s[ed.i].poid = 0;
	while(++ed.a < e->leng_salle)
	{
		if(ed.bol == 0)
		{
			ed.z = -1;
			while(++ed.z < e->leng_salle)
			{
				ed.y = -1;
				while(++ed.y < e->s[ed.z].size_bridg)
				{
					if(e->s[ed.z].bridg[ed.y] == e->s[ed.i].nb_salle)
						e->s[ed.z].poid = 1;
				}
			}
		}
		else
			edit_poid2(e, &ed);
		ed.bol = 1;
	}
}
