/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:25:56 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/23 18:47:49 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

wchar_t	*ft_largeur_uni_6(wchar_t *str, t_glob *g, int bol)
{
	int		i;
	int		s;
	wchar_t	*tmp;

	if ((int)ft_uni_strlen(str) < g->flag_largeur && !g->flag_neg &&
			g->flag_0 && bol)
	{
		if (!(tmp = (wchar_t *)malloc(sizeof(wchar_t) *
			(1 + g->flag_largeur))))
			return (NULL);
		i = ft_absolut(ft_uni_strlen(str) - g->flag_largeur) + 1;
		s = 0;
		tmp[0] = '-';
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

wchar_t	*ft_uni_string2(wchar_t *str, t_glob *g, int bol)
{
	if (!(str = ft_largeur_uni_3(str, g, bol)))
		return (NULL);
	if (!(str = ft_largeur_uni_4(str, g, bol)))
		return (NULL);
	if (!(str = ft_largeur_uni_5(str, g, bol)))
		return (NULL);
	if (!(str = ft_largeur_uni_6(str, g, bol)))
		return (NULL);
	return (str);
}

int		ft_uni_string(va_list *ap, t_glob *g)
{
	wchar_t	*str;
	int		bol;

	bol = 0;
	str = va_arg(ap[0], wchar_t *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (!(str = ft_presision_uni1(str, g, bol)))
		return (-1);
	if (!(str = ft_presision_uni3(str, g, bol)))
		return (-1);
	if (!(str = ft_presision_uni2(str, g, bol)))
		return (-1);
	if (!(str = ft_largeur_uni_1(str, g)))
		return (-1);
	if (!(str = ft_largeur_uni_2(str, g)))
		return (-1);
	if (!(str = ft_uni_string2(str, g, bol)))
		return (-1);
	return (ft_uni_putstr(str));
}
