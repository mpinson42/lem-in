/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:09:48 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/05 15:10:37 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

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

int		ft_get_salle(t_env *e, char *str, int *start, int *end)
{
	char	**tab;
	t_salle	*tmp;
	int		i;

	i = -1;
	tmp = e->s;
	tab = ft_strsplit(str, ' ');
	if (ft_strlen_tab(tab) != 3 || tab[2][0] == '\n')
		return (-1);
	if (!(e->s = (t_salle *)malloc(sizeof(t_salle) * (e->leng_salle + 1))))
		return (-1);
	while (++i < e->leng_salle)
		e->s[i] = tmp[i];
	e->s[i].nb_salle = ft_atoi(tab[0]);
	e->s[i].x = ft_atoi(tab[1]);
	e->s[i].y = ft_atoi(tab[2]);
	e->s[i].size_bridg = 0;
	e->s[i].poid = 255;
	e->leng_salle++;
	e->s[i].is_full = 0;
	if (start[0] == 1)
	{
		e->s[i].is_full = e->nb_fourmi;
		e->s[i].start = 1;
	}
	else
		e->s[i].start = 0;
	if (end[0] == 1)
		e->s[i].end = 1;
	else
		e->s[i].end = 0;
	return (0);
}

int	ft_bridg(t_env *e, int bridg, int i)
{
	int *tmp;
	int y;

	y = -1;
	while (++y < e->s[i].size_bridg)
	{
		if (e->s[i].bridg[y] == bridg)
			return (-1);
	}
	tmp = e->s[i].bridg;
	if (!(e->s[i].bridg = (int *)malloc(sizeof(int) *
					(e->s[i].size_bridg + 1))))
		return (-1);
	y = -1;
	while (++y < e->s[i].size_bridg)
		e->s[i].bridg[y] = tmp[y];
	e->s[i].bridg[y] = bridg;
	e->s[i].size_bridg++;
	return (0);
}

int		ft_pars_check_htag(t_env *e, t_pars *p)
{
	if (p->str[0] == '#' && ft_strcmp(p->str, "##end") != 0 &&
			ft_strcmp(p->str, "##start") != 0)
		return (-1);
	if (p->status == -1)
	{
		while (p->str[++p->i])
		{
			if ((ft_isdigit(p->str[p->i]) == 0 && p->str[p->i] != '\n')
					|| p->str[0] == '\n')
				p->stop = 1;
		}
		if (p->stop == 1)
			return (-2);
		e->nb_fourmi = ft_atoi(p->str);
		p->status = 0;
		ft_putstr(p->str);
		ft_putstr("\n");
		return (-1);
	}
	return (0);
}

int		ft_pars_check_htag2(t_env *e, t_pars *p)
{
	if (p->str[0] == 0)
		return (-2);
	if (ft_pars_check_htag(e, p) == -1)
		return (-1);
	if (ft_pars_check_htag(e, p) == -2)
		return (-2);
	if (ft_strcmp(p->str, "##start") == 0 && p->start == 0)
	{
		p->start++;
		ft_putstr(p->str);
		ft_putstr("\n");
		return (-1);
	}
	if (ft_strcmp(p->str, "##start") == 0)
		return (-2);
	if (ft_strcmp(p->str, "##end") == 0 && p->end == 0)
	{
		p->end++;
		ft_putstr(p->str);
		ft_putstr("\n");
		return (-1);
	}
	if (ft_strcmp(p->str, "##end\n") == 0)
		return (-2);
	return (0);
}

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
		if (ft_get_bridg(e, p->str) == -1)
			return (-1);
		if (p->count != 1)
			return (-1);
		ft_putstr(p->str);
		ft_putstr("\n");
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
		if ((ft_isdigit(p->str[p->i]) == 0 && p->str[p->i] != '-' &&
					p->str[p->i] != ' ' && p->str[p->i] != '\n')
				|| p->count >= 2)
			p->stop = 1;
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
	while (get_next_line(0, &p->str))
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
			ft_putstr(p->str);
			ft_putstr("\n");
		}
		if (phase2(e, p) == -1)
			break ;
	}
}

void setup(t_env *e)
{
	
}

int		ft_pars(t_env *e)
{
	t_pars p;

	ft_bzero(e, sizeof(e));
	ft_bzero(&p, sizeof(p));
	p.status = -1;
	ft_get_line(e, &p);
	if (p.start != 2 || p.end != 2 || e->leng_salle < 2 || e->nb_fourmi <= 0)
	{
		ft_putstr("ERROR");
		return (-1);
	}
	e->s[e->leng_salle].size_bridg = 0;
	p.i = -1;
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
