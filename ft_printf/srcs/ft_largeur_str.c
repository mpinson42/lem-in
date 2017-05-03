/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_largeur_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:39:48 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 17:39:55 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_largeur_str1(char *str, t_glob *g)
{
	int		s;
	int		i;
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

char	*ft_largeur_str2(char *str, t_glob *g)
{
	int		s;
	int		i;
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

char	*ft_largeur_str3(char *str, t_glob *g, int bol)
{
	int		s;
	int		i;
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

char	*ft_largeur_str4(char *str, t_glob *g, int bol)
{
	int		s;
	int		i;
	char	*tmp;

	if ((int)ft_strlen(str) < g->flag_largeur && !g->flag_neg && g->flag_0
			&& !bol && g->flag_more)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (1 + g->flag_largeur))))
			return (NULL);
		i = ft_absolut(ft_strlen(str) - g->flag_largeur) + 1;
		s = 0;
		tmp[0] = '+';
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

char	*ft_largeur_str5(char *str, t_glob *g, int bol)
{
	int		s;
	int		i;
	char	*tmp;

	if ((int)ft_strlen(str) < g->flag_largeur && !g->flag_neg && g->flag_0
			&& !bol && g->flag_space)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (1 + g->flag_largeur))))
			return (NULL);
		i = ft_absolut(ft_strlen(str) - g->flag_largeur) + 1;
		s = 0;
		tmp[0] = ' ';
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
