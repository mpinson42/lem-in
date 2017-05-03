/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_largeur_int2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:39:27 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 17:39:32 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_largeur_int6(char *str, t_glob *g, int bol)
{
	int		i;
	int		s;
	char	*tmp;

	if ((int)ft_strlen(str) < g->flag_largeur && !g->flag_neg && g->flag_0 &&
			!bol && g->flag_more && g->type != 'u' && g->type != 'U')
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (1 + g->flag_largeur))))
			return (NULL);
		i = ft_absolut(ft_strlen(str) - g->flag_largeur) + 1;
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

char	*ft_largeur_int7(char *str, t_glob *g, int bol)
{
	int		i;
	int		s;
	char	*tmp;

	if ((int)ft_strlen(str) < g->flag_largeur && !g->flag_neg && g->flag_0 &&
			!bol && g->flag_space && g->type != 'u' && g->type != 'U')
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (1 + g->flag_largeur))))
			return (NULL);
		i = ft_absolut(ft_strlen(str) - g->flag_largeur) + 1;
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

char	*ft_largeur_int8(char *str, t_glob *g, int bol)
{
	int		i;
	int		s;
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
		i = 1;
		while (s < g->flag_largeur + 1)
			tmp[s++] = str[i++];
		tmp[s] = 0;
		str = tmp;
	}
	return (str);
}
