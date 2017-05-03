/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:27:32 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/05 18:59:40 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <limits.h>

int	ft_color2(char *str, int *i)
{
	if (ft_strcmp(ft_strsub(str, i[0], 5), "{red}") == 0)
		return (write(1, "\e[0;31m", 8) - 3);
	if (ft_strcmp(ft_strsub(str, i[0], 6), "{pink}") == 0)
		return (write(1, "\e[1;31m", 8) - 2);
	if (ft_strcmp(ft_strsub(str, i[0], 12), "{dark_green}") == 0)
		return (write(1, "\e[0;32m", 8) + 4);
	if (ft_strcmp(ft_strsub(str, i[0], 7), "{green}") == 0)
		return (write(1, "\e[1;32m", 8) - 1);
	if (ft_strcmp(ft_strsub(str, i[0], 8), "{orange}") == 0)
		return (write(1, "\e[0;33m", 8));
	if (ft_strcmp(ft_strsub(str, i[0], 8), "{yellow}") == 0)
		return (write(1, "\e[1;33m", 8));
	if (ft_strcmp(ft_strsub(str, i[0], 11), "{dark_blue}") == 0)
		return (write(1, "\e[0;34m", 8) + 3);
	if (ft_strcmp(ft_strsub(str, i[0], 6), "{blue}") == 0)
		return (write(1, "\e[1;34m", 8) - 2);
	if (ft_strcmp(ft_strsub(str, i[0], 13), "{dark_purpel}") == 0)
		return (write(1, "\e[0;35m", 8) + 5);
	if (ft_strcmp(ft_strsub(str, i[0], 8), "{purpel}") == 0)
		return (write(1, "\e[1;35m", 8));
	if (ft_strcmp(ft_strsub(str, i[0], 11), "{dark_cyan}") == 0)
		return (write(1, "\e[0;36m", 8) + 3);
	if (ft_strcmp(ft_strsub(str, i[0], 6), "{cyan}") == 0)
		return (write(1, "\e[1;36m", 8) - 2);
	return (-1);
}

int	ft_color(char *str, int *i)
{
	if (ft_strcmp(ft_strsub(str, i[0], 11), "{dark_grey}") == 0)
		return (write(1, "\e[0;37m", 8) + 3);
	if (ft_strcmp(ft_strsub(str, i[0], 7), "{white}") == 0)
		return (write(1, "\e[1;37m", 8) - 1);
	if (ft_strcmp(ft_strsub(str, i[0], 7), "{black}") == 0)
		return (write(1, "\e[0;30m", 8) - 1);
	if (ft_strcmp(ft_strsub(str, i[0], 6), "{grey}") == 0)
		return (write(1, "\e[1;30m", 8) - 2);
	if (ft_strcmp(ft_strsub(str, i[0], 5), "{eoc}") == 0)
		return (write(1, "\e[0;m", 6) - 1);
	if (ft_strcmp(ft_strsub(str, i[0], 5), "{cls}") == 0)
		return (write(1, "\033[H\033[2", 12) - 7);
	return (ft_color2(str, i));
}

int	ft_pars_suit(int *i, int *rendu, char *str, va_list *ap)
{
	int tmp;

	if (str[i[0]] == '{')
		ft_parant(i, rendu, str);
	else if (str[i[0]] == '%')
	{
		i[0]++;
		if ((tmp = ft_lecture(i, str, ap)) == -1)
			return (-1);
		rendu[0] = rendu[0] + tmp;
		while (str[i[0]] && (ft_strchr("-+ #.*hlLjz", str[i[0]]) != NULL
					|| ft_isdigit(str[i[0]])))
			i[0]++;
		i[0]++;
	}
	else if (str[i[0]] && i[0] < (int)ft_strlen(str))
	{
		ft_uni_putchar(str[i[0]]);
		rendu[0]++;
		i[0]++;
	}
	else
		i[0]++;
	return (0);
}

int	ft_pars(va_list *ap, char *str)
{
	int i;
	int rendu;
	int test[1];

	i = 0;
	rendu = 0;
	if (str == NULL)
		ft_putstr("(NULL)");
	if (str[0] && str[0] == '%' && str[1] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'n')
		{
			test[0] = rendu;
			*(va_arg(*ap, int *)) = *test;
			i = i + 2;
		}
		if (ft_pars_suit(&i, &rendu, str, ap) == -1)
			return (-1);
	}
	return (rendu);
}

int	ft_printf(char *str, ...)
{
	int		i;
	va_list	ap;

	va_start(ap, str);
	i = ft_pars(&ap, str);
	va_end(ap);
	return (i);
}
