/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_htag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:46:29 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/28 20:36:54 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_pars_check_htag(t_env *e, t_pars *p)
{
	if (p->str[0] == '#' && ft_strcmp(p->str, "##end") != 0 &&
			ft_strcmp(p->str, "##start") != 0 && p->str[1] != '#')
	{
		p->map = ft_strjoin(p->map, ft_strjoin(p->str, "\n"));
		return (-1);
	}
	if (p->str[0] == '#' && p->str[1] == '#' && ft_strcmp(p->str, "##end")
		!= 0 && ft_strcmp(p->str, "##start") != 0)
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
		p->map = ft_strjoin(p->map, ft_strjoin(p->str, "\n"));
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
		p->map = ft_strjoin(p->map, p->str);
		p->map = ft_strjoin(p->map, "\n");
		return (-1);
	}
	if (ft_strcmp(p->str, "##start") == 0)
		return (-2);
	if (ft_strcmp(p->str, "##end") == 0 && p->end == 0)
	{
		p->end++;
		p->map = ft_strjoin(p->map, p->str);
		p->map = ft_strjoin(p->map, "\n");
		return (-1);
	}
	if (ft_strcmp(p->str, "##end\n") == 0)
		return (-2);
	return (0);
}

void	ft_assigne_lemin(t_env *e, int *start, int *end, int i)
{
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
}

int		ft_get_salle(t_env *e, char *str, int *start, int *end)
{
	char		**tab;
	t_salle		*tmp;
	int			i;

	i = -1;
	tmp = e->s;
	tab = ft_strsplit(str, ' ');
	if (ft_strlen_tab(tab) != 3 || tab[2][0] == '\n')
		return (-1);
	if (ft_str_is_digit(tab[2], tab[1], tab[0]) == -1)
		return (-1);
	if (!(e->s = (t_salle *)malloc(sizeof(t_salle) * (e->leng_salle + 1))))
		exit(0);
	while (++i < e->leng_salle)
		e->s[i] = tmp[i];
	e->s[i].name = tab[0];
	e->s[i].nb_salle = ++e->salle;
	e->s[i].x = ft_atoi(tab[1]);
	e->s[i].y = ft_atoi(tab[2]);
	e->s[i].size_bridg = 0;
	e->s[i].poid = 255;
	e->leng_salle++;
	e->s[i].is_full = 0;
	ft_assigne_lemin(e, start, end, i);
	return (0);
}

int		ft_bridg(t_env *e, int bridg, int i)
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
		exit(0);
	y = -1;
	while (++y < e->s[i].size_bridg)
		e->s[i].bridg[y] = tmp[y];
	e->s[i].bridg[y] = bridg;
	e->s[i].size_bridg++;
	return (0);
}
