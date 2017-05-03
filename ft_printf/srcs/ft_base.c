/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:23:59 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/23 18:46:55 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_htag(char *str, t_glob *g)
{
	int s;

	s = -1;
	if (g->flag_htag && ft_strcmp("0", str) && !g->flag_0 && (g->type == 'X'
				|| g->type == 'x'))
		str = ft_strjoin("0x", str);
	if (g->presision == 0 && (int)ft_strlen(str) == 1 && str[0] == '0')
		str = "";
	if (g->flag_htag && ft_strcmp("0", str) && !g->flag_0 && (g->type == 'o'
				|| g->type == 'O') && !g->flag_neg && g->flag_htag)
		str = ft_strjoin("0", str);
	if (g->flag_htag && ft_strcmp("0", str) && !g->flag_0 && (g->type == 'o'
				|| g->type == 'O') && g->flag_neg)
		str = ft_strjoin("0", str);
	while ((g->type == 'X' || g->type == 'O') && str[++s])
		str[s] = ft_toupper(str[s]);
	return (str);
}

char	*ft_presision_base(char *str, t_glob *g, int *bol)
{
	long long	test;
	char		*tmp;
	int			i;

	if (g->presision != -1 && g->presision > (int)ft_strlen(str) && !bol[0])
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
		bol[0] = 1;
	}
	str = ft_htag(str, g);
	return (str);
}

char	*ft_debug_base(char *str, t_glob *g)
{
	int		i;
	int		s;
	char	*tmp;

	if (g->flag_0 && g->flag_htag && g->type == 'x' &&
			g->flag_largeur > (int)ft_strlen(str) - 2)
		str[1] = 'x';
	if (g->flag_htag && g->type == 'o' && g->presision != -1
		&& g->presision != 0)
	{
		i = (int)ft_strlen(str);
		s = -1;
		if (!(tmp = (char *)malloc(sizeof(char) * i)))
			return (NULL);
		while (++s < i)
			tmp[s] = str[s + 1];
		str = tmp;
	}
	if (str[0] == 0 && g->flag_htag && g->presision == 0 && g->type == 'o')
		str = "0";
	return (str);
}

char	*ft_base2(char *str, t_glob *g, int bol)
{
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
	if (!(str = ft_debug_base(str, g)))
		return (NULL);
	return (str);
}

int		ft_base(va_list *ap, t_glob *g)
{
	char		*str;
	int			i;
	int			s;
	int			bol;

	s = -1;
	i = 0;
	bol = 0;
	str = NULL;
	str = ft_conv_base1(str, g, ap);
	str = ft_conv_base2(str, ap, g);
	str = ft_conv_base3(str, ap, g);
	if (!(str = ft_conv_base4(str, ap, g)))
		return (-1);
	if (!(str = ft_presision_base(str, g, &bol)))
		return (-1);
	if (!(str = ft_largeur_int1(str, g, bol)))
		return (-1);
	if (!(str = ft_largeur_int2(str, g, bol)))
		return (-1);
	if (!(str = ft_base2(str, g, bol)))
		return (-1);
	ft_putstr(str);
	return ((int)ft_strlen(str));
}
