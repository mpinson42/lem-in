/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:40:46 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 17:40:48 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_largeur(int i, t_glob *g, char c)
{
	int tmp;

	i = g->flag_largeur - i - 1;
	if (g->flag_more == 1)
		i--;
	tmp = i;
	while (i >= 0)
	{
		ft_putchar(c);
		i--;
	}
	return (tmp);
}

int		ft_pourcent(t_glob *g)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup("%");
	while (g->flag_0 == 0 && g->flag_neg == 0 && g->presision == -1
		&& ++i < g->flag_largeur)
		str = ft_strjoin(" ", str);
	while (g->flag_0 == 0 && g->flag_neg == 0 && g->presision > -1
		&& ++i < g->flag_largeur)
		str = ft_strjoin("0", str);
	while (g->flag_0 == 1 && g->flag_neg == 0 && ++i < g->flag_largeur)
		str = ft_strjoin("0", str);
	while (++i < g->flag_largeur && g->flag_neg == 1)
		str = ft_strjoin(str, " ");
	return (write(1, str, ft_strlen(str)));
}

char	*ft_pressison(t_glob *g, char *str)
{
	int		i;
	int		y;
	char	*tmp;

	i = 2;
	y = 0;
	if (!(tmp = malloc(sizeof(char) * (g->presision + 1))))
		return (NULL);
	ft_bzero(tmp, ft_strlen(str) + 1);
	if (g->presision != -1)
	{
		while (y < g->presision - (int)ft_strlen(str) + 2)
		{
			tmp[y] = '0';
			y++;
		}
		while (str[i] && i < g->presision)
		{
			tmp[y] = str[i];
			y++;
			i++;
		}
		str = ft_strjoin("0x", tmp);
	}
	return (str);
}

char	*presison_ptr(t_glob *g, char *str, char *ptr, int tmp)
{
	int i;

	if ((int)ft_strlen(ptr) < g->flag_largeur && !g->flag_neg && !g->flag_0)
	{
		if (!(str = (char *)malloc(sizeof(char) * (1 + g->flag_largeur))))
			return (NULL);
		i = ft_absolut(ft_strlen(ptr) - g->flag_largeur);
		while (++tmp < i)
			str[tmp] = ' ';
		i = 0;
		while (tmp < g->flag_largeur)
			str[tmp++] = ptr[i++];
	}
	if ((int)ft_strlen(ptr) < g->flag_largeur && !g->flag_neg && g->flag_0)
	{
		if (!(str = (char *)malloc(sizeof(char) * (1 + g->flag_largeur))))
			return (NULL);
		i = ft_absolut(ft_strlen(ptr) - g->flag_largeur);
		i = -1;
		while (++i < (int)ft_strlen(ptr))
			str[i] = ptr[i];
		while (i < g->flag_largeur)
			str[i++] = '0';
	}
	return (str);
}

int		ft_pointeur(va_list *ap, t_glob *g)
{
	char	*ptr;
	char	*str;
	int		i;

	i = -1;
	if (!(ptr = ft_strjoin("0x",
		ft_itoa_base((uintmax_t)va_arg(ap[0], void *), 16))))
		return (-1);
	str = ptr;
	if (!(str = ft_pressison(g, str)))
		return (-1);
	if (!(str = presison_ptr(g, str, ptr, i)))
		return (-1);
	if ((int)ft_strlen(ptr) < g->flag_largeur && g->flag_neg && !g->flag_0)
	{
		if (!(str = (char *)malloc(sizeof(char) * (1 + g->flag_largeur))))
			return (-1);
		while (++i < (int)ft_strlen(ptr))
			str[i] = ptr[i];
		while (i < g->flag_largeur)
			str[i++] = ' ';
	}
	ft_putstr(str);
	return (ft_strlen(str));
}
