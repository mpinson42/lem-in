/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:09:48 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/28 20:35:03 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		phase2(t_env *e, t_pars *p)
{
	if (p->status == 1)
	{
		p->i = -1;
		while (p->str[++p->i])
		{
			if (p->str[p->i] == ' ')
				p->stop = 1;
		}
		if (p->stop == 1)
			return (-1);
		if (ft_get_bridg(e, p->str, -1) == -1)
			return (-1);
		if (p->count != 1)
			return (-1);
		p->map = ft_strjoin(p->map, p->str);
		p->map = ft_strjoin(p->map, "\n");
	}
	if (p->start == 1)
		p->start++;
	if (p->end == 1)
		p->end++;
	return (0);
}

int		ft_chois_phase(t_env *e, t_pars *p)
{
	if (ft_pars_check_htag2(e, p) == -2)
		return (-1);
	p->i = -1;
	while (p->str[++p->i])
	{
		if (p->str[p->i] == ' ')
			p->count_sapce++;
		if (p->str[p->i] == '-' && p->str[p->i] + 1 == '\n')
			p->stop = 1;
		if (p->str[p->i] == '-')
		{
			p->status = 1;
			p->count++;
		}
	}
	if (p->stop == 1)
		return (-1);
	return (0);
}

void	ft_get_line(t_env *e, t_pars *p)
{
	while (get_next_line(0, &p->str) >= 0)
	{
		p->count_sapce = 0;
		p->i = -1;
		p->count = 0;
		if (p->str[0] == 0)
			break ;
		if (ft_pars_check_htag2(e, p) == -1)
			continue ;
		if (ft_chois_phase(e, p) == -1)
			break ;
		if (p->stop == 1)
			break ;
		if (p->status == 0)
		{
			if (p->count_sapce != 2)
				break ;
			if (ft_get_salle(e, p->str, &p->start, &p->end) == -1)
				break ;
			p->map = ft_strjoin(p->map, p->str);
			p->map = ft_strjoin(p->map, "\n");
		}
		if (phase2(e, p) == -1)
			break ;
	}
}

int		setup(t_env *e, t_pars *p)
{
	ft_bzero(e, sizeof(e));
	ft_bzero(p, sizeof(p[0]));
	p->save = NULL;
	p->status = -1;
	p->map = ft_strdup("");
	ft_get_line(e, p);
	ft_putstr(p->map);
	if (p->start != 2 || p->end != 2 || e->leng_salle < 2 || e->nb_fourmi <= 0)
	{
		ft_putstr("ERROR");
		return (-1);
	}
	e->s[e->leng_salle].size_bridg = 0;
	p->i = -1;
	return (0);
}

int		ft_parsing(t_env *e)
{
	t_pars p;

	if (setup(e, &p) == -1)
		return (-1);
	while (++p.i < e->leng_salle)
	{
		p.stop = -1;
		while (++p.stop < e->leng_bridg)
		{
			if (e->s[p.i].nb_salle == e->b[p.stop].bridg_1)
				ft_bridg(e, e->b[p.stop].bridg_2, p.i);
			if (e->s[p.i].nb_salle == e->b[p.stop].bridg_2)
				ft_bridg(e, e->b[p.stop].bridg_1, p.i);
		}
	}
	edit_poid(e);
	p.i = 0;
	while (e->s[p.i].start != 1)
		p.i++;
	if (e->s[p.i].poid == 255)
	{
		e->s[p.i].poid = e->poid_max + 1;
		e->poid_max++;
	}
	return (55);
}
