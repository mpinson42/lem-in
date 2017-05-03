/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:25:22 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/23 18:47:40 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_largeur_str6(char *str, t_glob *g, int bol)
{
	int		s;
	int		i;
	char	*tmp;

	if ((int)ft_strlen(str) < g->flag_largeur && !g->flag_neg &&
			g->flag_0 && bol)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (1 + g->flag_largeur))))
			return (NULL);
		i = ft_absolut(ft_strlen(str) - g->flag_largeur) + 1;
		s = 0;
		tmp[0] = '-';
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

char	*ft_string2(char *str, t_glob *g, int bol)
{
	if (!(str = ft_largeur_str3(str, g, bol)))
		return (NULL);
	if (!(str = ft_largeur_str4(str, g, bol)))
		return (NULL);
	if (!(str = ft_largeur_str5(str, g, bol)))
		return (NULL);
	if (!(str = ft_largeur_str6(str, g, bol)))
		return (NULL);
	return (str);
}

int		ft_string(va_list *ap, t_glob *g)
{
	char	*str;
	int		bol;

	bol = 0;
	if (g->flagl)
		return (ft_uni_string(ap, g));
	str = va_arg(ap[0], char *);
	if (str == NULL)
		if (!(str = ft_strdup("(null)")))
			return (-1);
	if (!(str = ft_presision_str1(str, g, bol)))
		return (-1);
	if (!(str = ft_presision_str2(str, g, bol)))
		return (-1);
	if (!(str = ft_largeur_str1(str, g)))
		return (-1);
	if (!(str = ft_largeur_str2(str, g)))
		return (-1);
	if (!(str = ft_string2(str, g, bol)))
		return (-1);
	ft_putstr(str);
	return ((int)ft_strlen(str));
}
