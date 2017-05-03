/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:27:32 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/23 18:47:23 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_next(t_glob *g, char *str, int *i, int *dot)
{
	char *tmp;

	tmp = NULL;
	str[*i] == '#' ? g->flag_htag = 1 : 0;
	str[*i] == '-' ? g->flag_neg = 1 : 0;
	if (str[*i] == '+')
		g->flag_more = 1;
	if (str[*i] == '.')
	{
		i[0]++;
		while (str[*i] && ft_isdigit(str[*i]))
			if (!(tmp = ft_strjoin_char2(tmp, str[i[0]++])))
				return (-1);
		i[0]--;
		if (tmp)
			g->presision = ft_atoi(tmp);
		else
			g->presision = 0;
		dot[0] = 1;
		tmp = NULL;
	}
	if (str[*i] == ' ')
		g->flag_space = 1;
	return (0);
}

int		ft_next2(char *str, int *i, int *tab, t_glob *g)
{
	char *tmp2;

	tmp2 = NULL;
	if (str[*i] && ft_isdigit(str[*i]) && tab[1] == 1 && tab[0] == 0)
	{
		while (str[*i] && ft_isdigit(str[*i]))
			if (!(tmp2 = ft_strjoin_char2(tmp2, str[i[0]++])))
				return (-1);
		i[0]--;
		if (g->presision > 0 && tab[0] == 1 && g->flag_largeur < ft_atoi(tmp2))
			g->flag_largeur = ft_atoi(tmp2) / 10;
		else if (g->flag_largeur < ft_atoi(tmp2))
			g->flag_largeur = ft_atoi(tmp2);
		tmp2 = NULL;
	}
	return (0);
}

int		ft_search_flag(t_glob *g, char *str, int *i)
{
	int		tab[2];
	char	*tmp2;

	tab[0] = 0;
	tab[1] = 0;
	tmp2 = NULL;
	while (str[*i] && (ft_strchr("-+ #.hlLjz", str[*i]) != NULL
				|| ft_isdigit(str[*i])))
	{
		if (ft_isdigit(str[*i]) && str[*i] != '0')
			tab[1] = 1;
		if (ft_next(g, str, i, &tab[0]) == -1)
			return (-1);
		if (str[*i] == '0' && str[i[0] + 1] && str[i[0] + 1] != '%' &&
			!ft_isdigit(str[i[0] - 1]) && str[i[0] - 1] != '.')
		{
			g->flag_0 = 1;
			tab[1] = 1;
		}
		if (ft_next2(str, i, tab, g) == -1)
			return (-1);
		ft_assigne(str, i, g, &tab[0]);
	}
	return (ft_trie(g, str, i));
}

int		ft_lecture(int *i, char *str, va_list *ap)
{
	t_glob	g;
	int		count;

	ft_init(&g);
	if ((count = ft_search_flag(&g, str, i)) == -1)
		return (-1);
	if (count == 1)
		return (1);
	if (g.type == 'n')
		return (0);
	if (g.flagz == 1 && g.flagh == 1)
		g.flagh = 0;
	if (g.flagj == 1 && g.flagz == 1)
		g.flagj = 0;
	if (g.flagj == 1 && g.flagh == 1)
		g.flagh = 0;
	if (g.flagl == 1 && g.flagh == 2)
		g.flagh = 0;
	return (ft_choise(ap, &g));
}
