/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:46:18 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/05 19:46:19 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	start_(t_env *e, t_resolv *r)
{
	r->i = -1;
	r->save_one = 0;
	while (++r->i < e->leng_salle)
	{
		if (e->s[r->i].start == 1)
		{
			while (e->s[r->i].start == 1 && e->s[r->i].is_full &&
				r->save_one != -2)
				write_start(e, r);
		}
	}
}

int		ft_check_plyed(t_resolv *r, int formi)
{
	int i;

	i = 0;
	while (i < 255)
	{
		if (r->formi_played[i] == formi)
			return (-1);
		i++;
	}
	r->formi_played[r->played] = formi;
	r->played++;
	return (0);
}

void	check_bridg_start(t_env *e, t_resolv *r)
{
	r->y = -1;
	r->save_one = -1;
	while (++r->y < e->s[r->i].size_bridg)
	{
		r->z = -1;
		r->save = 255;
		while (++r->z < e->leng_salle)
		{
			if (e->s[r->i].bridg[r->y] == e->s[r->z].nb_salle && e->s[r->z].poid
					<= e->s[r->i].poid && e->s[r->z].poid < r->save &&
					(e->s[r->z].is_full == 0 || e->s[r->z].end == 1))
			{
				r->save_one = e->s[r->z].nb_salle;
				r->save = e->s[r->z].poid;
			}
		}
	}
}

void	write_start(t_env *e, t_resolv *r)
{
	check_bridg_start(e, r);
	if (r->save_one != -1)
	{
		r->z = -1;
		while (++r->z < e->leng_salle)
		{
			if (e->s[r->z].nb_salle == r->save_one)
			{
				e->s[r->z].is_full++;
				e->s[r->i].is_full--;
				e->s[r->z].num_fourmi = r->nb_fourmi;
				if (ft_printf("L%d-%s ", r->nb_fourmi, e->s[r->z].name) == -1)
					exit(0);
				r->nb_fourmi++;
			}
		}
	}
	else
		r->save_one = -2;
}
