/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:40:28 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 17:40:31 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_init(t_glob *g)
{
	g->flag_htag = 0;
	g->flag_largeur = 0;
	g->presision = -1;
	g->flag_0 = 0;
	g->flag_neg = 0;
	g->flag_more = 0;
	g->flag_space = 0;
	g->flagl = 0;
	g->flagh = 0;
	g->flagj = 0;
	g->flagz = 0;
	g->type = -1;
}

char	*ft_strjoin_char2(char *str, char c)
{
	char		*tmp;
	char		*tmp2;
	static int	i = 1;

	if (str == NULL)
	{
		if (!(str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = '\0';
		i = 0;
	}
	if (!(tmp = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	tmp[0] = c;
	tmp[1] = '\0';
	tmp2 = ft_strjoin(str, tmp);
	return (tmp2);
}

int		ft_trie(t_glob *g, char *str, int *i)
{
	g->type = str[*i];
	if ((g->flag_0 == 1 && g->flag_neg == 1) || (g->presision == 0
		&& (g->type == 'x' || g->type == 'X' || g->type == 'd' ||
			g->type == 'o' || g->type == 'O' || g->type == 'D')))
		g->flag_0 = 0;
	if (g->presision > 0 && g->type != 'S' && g->type != 's'
		&& g->type != 'c' && g->type != 'C')
		g->flag_0 = 0;
	if (g->flag_space == 1 && g->flag_more == 1)
		g->flag_space = 0;
	return (0);
}

void	ft_parant(int *i, int *rendu, char *str)
{
	int tmp;

	if ((tmp = ft_color(str, i)) == -1)
	{
		rendu[0] = rendu[0] + write(1, "{", 1);
		i[0]++;
	}
	else
		i[0] = i[0] + tmp;
}

void	ft_assigne(char *str, int *i, t_glob *g, int *dot)
{
	if (str[*i + 1] && str[*i] == 'h' && str[*i + 1] != 'h'
			&& str[*i - 1] != 'h')
		g->flagh = 1;
	if (str[*i + 1] && str[*i] == 'h' && str[*i + 1] == 'h')
		g->flagh = 2;
	if (str[i[0] + 1] && str[*i] == 'l' && str[i[0] + 1] != 'l'
			&& str[*i - 1] != 'l')
		g->flagl = 1;
	if (str[i[0] + 1] && str[*i] == 'l' && str[i[0] + 1] == 'l')
		g->flagl = 2;
	if (str[*i] == 'j')
		g->flagj = 1;
	if (str[*i] == 'z')
		g->flagz = 1;
	dot[0] = 0;
	i[0]++;
}
