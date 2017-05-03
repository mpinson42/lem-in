/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largeur_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:41:02 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 17:41:06 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_largeur_int1(char *str, t_glob *g, int bol)
{
	int		i;
	int		s;
	char	*tmp;

	if (g->flag_more && !bol && g->type != 'u' && g->type != 'U' && g->type
		!= 'o' && g->type != 'O' && g->type != 'x' && g->type != 'X')
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
			return (NULL);
		tmp[0] = '+';
		i = 1;
		s = 0;
		while (str[s])
			tmp[i++] = str[s++];
		tmp[i] = 0;
		str = tmp;
	}
	return (str);
}

char	*ft_largeur_int2(char *str, t_glob *g, int bol)
{
	int		i;
	int		s;
	char	*tmp;

	if (g->flag_space && !bol && g->type != 'u' && g->type != 'U' && g->type
		!= 'o' && g->type != 'O' && g->type != 'x' && g->type != 'X')
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
			return (NULL);
		tmp[0] = ' ';
		i = 1;
		s = 0;
		while (str[s])
			tmp[i++] = str[s++];
		tmp[i] = 0;
		str = tmp;
	}
	return (str);
}

char	*ft_largeur_int3(char *str, t_glob *g)
{
	int		i;
	int		s;
	char	*tmp;

	if ((int)ft_strlen(str) < g->flag_largeur && !g->flag_neg && !g->flag_0)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (1 + g->flag_largeur))))
			return (NULL);
		i = ft_absolut(ft_strlen(str) - g->flag_largeur);
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

char	*ft_largeur_int4(char *str, t_glob *g)
{
	int		i;
	int		s;
	char	*tmp;

	if ((int)ft_strlen(str) < g->flag_largeur && g->flag_neg && !g->flag_0)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (1 + g->flag_largeur))))
			return (NULL);
		i = ft_absolut(ft_strlen(str) - g->flag_largeur);
		s = -1;
		while (str[++s])
			tmp[s] = str[s];
		i = -1;
		while (++i < ft_absolut(ft_strlen(str) - g->flag_largeur))
			tmp[s++] = ' ';
		tmp[s] = 0;
		str = tmp;
	}
	return (str);
}

char	*ft_largeur_int5(char *str, t_glob *g, int bol)
{
	int		i;
	int		s;
	char	*tmp;

	if ((int)ft_strlen(str) < g->flag_largeur && !g->flag_neg && g->flag_0 &&
			!bol && !g->flag_more && !g->flag_space)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (1 + g->flag_largeur))))
			return (NULL);
		i = ft_absolut(ft_strlen(str) - g->flag_largeur);
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
