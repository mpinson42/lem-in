/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:49:55 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/05 18:08:26 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_bridg_no_start(t_env *e, t_resolv *r)
{
	r->y = -1;
	r->save_one = -1;
	r->save = 255;
	while (++r->y < e->s[r->i].size_bridg && e->s[r->i].start == 0 &&
			r->save_one != -2)
	{
		r->z = -1;
		while (++r->z < e->leng_salle)
		{
			if (e->s[r->i].bridg[r->y] == e->s[r->z].nb_salle &&
				e->s[r->z].poid <= e->s[r->i].poid && e->s[r->z].poid
				< r->save && (e->s[r->z].is_full
						== 0 || e->s[r->z].end == 1))
			{
				r->save_one = e->s[r->z].nb_salle;
				r->save = e->s[r->z].poid;
			}
		}
	}
}

void	write_no_start(t_env *e, t_resolv *r)
{
	if (r->save_one != -1)
	{
		r->z = -1;
		while (++r->z < e->leng_salle)
		{
			if (e->s[r->z].nb_salle == r->save_one)
			{
				e->s[r->z].is_full++;
				e->s[r->i].is_full--;
				e->s[r->z].num_fourmi = e->s[r->i].num_fourmi;
				e->s[r->i].num_fourmi = 0;
				ft_printf("L%d-%d ", e->s[r->z].num_fourmi,
					e->s[r->z].nb_salle);
			}
		}
	}
	else
		r->save_one = -2;
}

void	check_all_poid(t_env *e, t_resolv *r)
{
	r->i = -1;
	while (++r->i < e->leng_salle)
	{
		if (e->s[r->i].poid == r->poid && e->s[r->i].is_full)
		{
			while (e->s[r->i].start == 1 && e->s[r->i].is_full &&
				r->save_one != -2)
				write_start(e, r);
			check_bridg_no_start(e, r);
			write_no_start(e, r);
		}
	}
}

void	ft_resolv(t_env *e)
{
	t_resolv r;

	ft_bzero(&r, sizeof(r));
	r.nb_fourmi = 1;
	while (e->s[r.fin].end != 1)
		r.fin++;
	while (e->s[r.fin].is_full != e->nb_fourmi)
	{
		ft_printf("\n");
		r.poid = 0;
		ft_memset(r.fourmi, -1, 255);
		r.fourmiz = 0;
		while (++r.poid <= e->poid_max)
			check_all_poid(e, &r);
	}
}
