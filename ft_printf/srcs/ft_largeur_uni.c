/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_largeur_uni.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:40:08 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 17:40:12 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

wchar_t	*ft_largeur_uni_1(wchar_t *str, t_glob *g)
{
	int		i;
	int		s;
	wchar_t	*tmp;

	if ((int)ft_uni_strlen(str) < g->flag_largeur && !g->flag_neg && !g->flag_0)
	{
		if (!(tmp = (wchar_t *)malloc(sizeof(wchar_t) * (1 + g->flag_largeur))))
			return (NULL);
		i = ft_absolut(ft_uni_strlen(str) - g->flag_largeur);
		s = -1;
		while (++s < i)
			tmp[s] = ' ';
		i = 0;
		while (s < g->flag_largeur + 1)
			tmp[s++] = str[i++];
		tmp[s] = 0;
		str = tmp;
	}
	return (str);
}

wchar_t	*ft_largeur_uni_2(wchar_t *str, t_glob *g)
{
	int		i;
	int		s;
	wchar_t	*tmp;

	if ((int)ft_uni_strlen(str) < g->flag_largeur && g->flag_neg && !g->flag_0)
	{
		if (!(tmp = (wchar_t *)malloc(sizeof(wchar_t) * (1 + g->flag_largeur))))
			return (NULL);
		i = ft_absolut(ft_uni_strlen(str) - g->flag_largeur);
		s = -1;
		while (str[++s])
			tmp[s] = str[s];
		i = -1;
		while (++i < ft_absolut(ft_uni_strlen(str) - g->flag_largeur))
			tmp[s++] = ' ';
		tmp[s] = 0;
		str = tmp;
	}
	return (str);
}

wchar_t	*ft_largeur_uni_3(wchar_t *str, t_glob *g, int bol)
{
	int		i;
	int		s;
	wchar_t	*tmp;

	if ((int)ft_uni_strlen(str) < g->flag_largeur && !g->flag_neg &&
			g->flag_0 && !bol && !g->flag_more && !g->flag_space)
	{
		if (!(tmp = (wchar_t *)malloc(sizeof(wchar_t) * (1 + g->flag_largeur))))
			return (NULL);
		i = ft_absolut(ft_uni_strlen(str) - g->flag_largeur);
		s = -1;
		while (++s < i)
			tmp[s] = '0';
		i = 0;
		while (s < g->flag_largeur + 1)
			tmp[s++] = str[i++];
		tmp[s] = 0;
		str = tmp;
	}
	return (str);
}

wchar_t	*ft_largeur_uni_4(wchar_t *str, t_glob *g, int bol)
{
	int		i;
	int		s;
	wchar_t	*tmp;

	if ((int)ft_uni_strlen(str) < g->flag_largeur && !g->flag_neg &&
			g->flag_0 && !bol && g->flag_more)
	{
		if (!(tmp = (wchar_t *)malloc(sizeof(wchar_t) * (1 + g->flag_largeur))))
			return (NULL);
		i = ft_absolut(ft_uni_strlen(str) - g->flag_largeur) + 1;
		s = 0;
		tmp[0] = '+';
		while (++s < i)
			tmp[s] = '0';
		i = 1;
		while (s < g->flag_largeur + 1)
			tmp[s++] = str[i++];
		tmp[s] = 0;
		str = tmp;
	}
	return (str);
}

wchar_t	*ft_largeur_uni_5(wchar_t *str, t_glob *g, int bol)
{
	int		s;
	int		i;
	wchar_t	*tmp;

	if ((int)ft_uni_strlen(str) < g->flag_largeur && !g->flag_neg &&
			g->flag_0 && !bol && g->flag_space)
	{
		if (!(tmp = (wchar_t *)malloc(sizeof(wchar_t) * (1 + g->flag_largeur))))
			return (NULL);
		i = ft_absolut(ft_uni_strlen(str) - g->flag_largeur) + 1;
		s = 0;
		tmp[0] = ' ';
		while (++s < i)
			tmp[s] = '0';
		i = 1;
		while (s < g->flag_largeur + 1)
			tmp[s++] = str[i++];
		tmp[s] = 0;
		str = tmp;
	}
	return (str);
}
