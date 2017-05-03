/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presision_uni.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:40:38 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 17:40:40 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		couting(wchar_t n)
{
	int i;

	i = ft_strlen(ft_itoa_base(n, 2));
	if (i <= 7)
		return (1);
	if (i > 7 && i <= 11)
		return (2);
	if (i > 11 && i <= 16)
		return (3);
	if (i > 16 && i <= 21)
		return (4);
	return (0);
}

int		ft_wisascii(wchar_t *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 0 || str[i] > 128)
			return (1);
		i++;
	}
	return (0);
}

wchar_t	*ft_presision_uni1(wchar_t *str, t_glob *g, int bol)
{
	int		i;
	int		y;
	wchar_t	*tmp;

	y = 0;
	if (g->presision == 0)
		str = L"";
	if (g->presision != -1 && g->presision > 0 && !bol && ft_wisascii(str))
	{
		i = -1;
		if (!(tmp = (wchar_t *)malloc(sizeof(wchar_t) * (g->presision + 1))))
			return (NULL);
		while (y < g->presision)
		{
			tmp[i] = str[i];
			y = y + couting(str[i]);
			i++;
		}
		tmp[i] = 0;
		str = tmp;
	}
	return (str);
}

wchar_t	*ft_presision_uni2(wchar_t *str, t_glob *g, int bol)
{
	int		i;
	int		test;
	wchar_t	*tmp;

	if (g->presision != -1 && g->presision >= (int)ft_uni_strlen(str) && bol)
	{
		if (!(tmp = (wchar_t *)malloc(sizeof(wchar_t) * (g->presision + 2))))
			return (NULL);
		i = -2;
		test = 1;
		tmp[0] = '-';
		while (++i < ft_absolut((g->presision - (int)ft_uni_strlen(str))))
			tmp[i] = '0';
		i = 1;
		while (str[i])
			tmp[test++] = str[i++];
		tmp[test] = 0;
		str = tmp;
	}
	return (str);
}

wchar_t	*ft_presision_uni3(wchar_t *str, t_glob *g, int bol)
{
	int		i;
	wchar_t	*tmp;

	if (g->presision != -1 && g->presision > 0 && !bol && ft_wisascii(str) == 0)
	{
		i = -1;
		if (!(tmp = (wchar_t *)malloc(sizeof(wchar_t) * (g->presision + 1))))
			return (NULL);
		while (++i < g->presision)
			tmp[i] = str[i];
		tmp[i] = 0;
		str = tmp;
	}
	return (str);
}
