/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presision_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:41:13 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 17:41:15 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_presision_str1(char *str, t_glob *g, int bol)
{
	int		i;
	int		test;
	char	*tmp;

	if (g->presision == 0)
		str = "";
	if (g->presision != -1 && g->presision > 0 && !bol)
	{
		i = 0;
		if (!(tmp = (char *)malloc(sizeof(char) * (g->presision + 1))))
			return (NULL);
		test = 0;
		while (i < g->presision)
			tmp[i++] = str[test++];
		tmp[i] = 0;
		str = tmp;
	}
	return (str);
}

char	*ft_presision_str2(char *str, t_glob *g, int bol)
{
	int		i;
	int		test;
	char	*tmp;

	if (g->presision != -1 && g->presision >= (int)ft_strlen(str) && bol)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (g->presision + 2))))
			return (NULL);
		i = -2;
		test = 1;
		tmp[0] = '-';
		while (++i < ft_absolut((g->presision - (int)ft_strlen(str))))
			tmp[test++] = '0';
		i = 1;
		while (str[i])
			tmp[test++] = str[i++];
		tmp[test] = 0;
		str = tmp;
	}
	return (str);
}
