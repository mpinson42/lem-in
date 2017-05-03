/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:24:49 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/23 18:47:16 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_presision_int1(char *str, t_glob *g, int bol)
{
	int				i;
	char			*tmp;
	long long int	test;

	if (g->presision != -1 && g->presision > (int)ft_strlen(str) && !bol)
	{
		i = -1;
		if (!(tmp = (char *)malloc(sizeof(char) * (g->presision + 1))))
			return (NULL);
		while (++i < ft_absolut((g->presision - (int)ft_strlen(str))))
			tmp[i] = '0';
		test = 0;
		while (i < g->presision)
			tmp[i++] = str[test++];
		tmp[i] = 0;
		str = tmp;
	}
	return (str);
}

char	*ft_presision_int2(char *str, t_glob *g, int bol)
{
	int				i;
	char			*tmp;
	long long int	test;

	if (g->presision != -1 && g->presision >= (int)ft_strlen(str) && bol)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (g->presision + 2))))
			return (NULL);
		i = -2;
		test = 1;
		tmp[0] = '-';
		while (++i < ft_absolut((g->presision - (int)ft_strlen(str))))
			tmp[test++] = '0';
		i = 0;
		while (str[i])
			tmp[test++] = str[++i];
		tmp[test] = 0;
		str = tmp;
	}
	return (str);
}

char	*ft_int2(char *str, t_glob *g, int bol)
{
	if (!(str = ft_largeur_int2(str, g, bol)))
		return (NULL);
	if (!(str = ft_largeur_int3(str, g)))
		return (NULL);
	if (!(str = ft_largeur_int4(str, g)))
		return (NULL);
	if (!(str = ft_largeur_int5(str, g, bol)))
		return (NULL);
	if (!(str = ft_largeur_int6(str, g, bol)))
		return (NULL);
	if (!(str = ft_largeur_int7(str, g, bol)))
		return (NULL);
	if (!(str = ft_largeur_int8(str, g, bol)))
		return (NULL);
	return (str);
}

int		ft_int(va_list *ap, t_glob *g)
{
	char			*str;
	int				bol;

	str = NULL;
	bol = 0;
	str = ft_conv_int1(str, g, ap, &bol);
	str = ft_conv_int2(str, g, ap, &bol);
	str = ft_conv_int3(str, g, ap, &bol);
	str = ft_conv_int4(str, g, ap, &bol);
	if (!(str = ft_conv_int5(str, g, ap)))
		return (-1);
	if (!(str = ft_presision_int1(str, g, bol)))
		return (-1);
	if (!(str = ft_presision_int2(str, g, bol)))
		return (-1);
	if (!(str = ft_largeur_int1(str, g, bol)))
		return (-1);
	if (!(str = ft_int2(str, g, bol)))
		return (-1);
	ft_putstr(str);
	return ((int)ft_strlen(str));
}
