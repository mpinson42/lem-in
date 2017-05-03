/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:38:39 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 17:38:43 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_conv_int1(char *str, t_glob *g, va_list *ap, int *bol)
{
	int			s;
	long long	test;

	if ((g->type == 'd' || g->type == 'i') && !g->flagh && !g->flagl &&
			!g->flagj && !g->flagz)
	{
		s = va_arg(ap[0], int);
		if (s < 0)
			bol[0] = 1;
		str = ft_itoa(s);
	}
	if (g->type == 'D' && !g->flagh && !g->flagl && !g->flagj && !g->flagz)
	{
		test = va_arg(ap[0], long int);
		if (test < 0)
			bol[0] = 1;
		str = ft_itoa_base(test, 10);
	}
	if (g->type == 'f' || g->type == 'F')
		str = ft_ftoa((float)va_arg(ap[0], double), g->presision);
	if ((g->type == 'u' || g->type == 'U' || g->type == 'D') && g->flagh == 1 &&
			!g->flagl && !g->flagj && !g->flagz)
		str = unsigned_itoa_base(va_arg(ap[0], long int), 10);
	return (str);
}

char	*ft_conv_int2(char *str, t_glob *g, va_list *ap, int *bol)
{
	int i;

	if ((g->type == 'd' || g->type == 'i') && g->flagh == 1 &&
			!g->flagl && !g->flagj && !g->flagz)
	{
		str = ft_itoa_base((short int)va_arg(ap[0], int), 10);
		i = ft_atoi(str);
		if (i < 0)
			bol[0] = 1;
	}
	if ((g->type == 'd' || g->type == 'i') && g->flagh == 2 &&
			!g->flagl && !g->flagj && !g->flagz)
		str = ft_itoa_base((signed char)va_arg(ap[0], int), 10);
	return (str);
}

char	*ft_conv_int3(char *str, t_glob *g, va_list *ap, int *bol)
{
	int i;

	if (g->type == 'u' && g->flagh == 2 && !g->flagl && !g->flagj
			&& !g->flagz)
		str = unsigned_itoa_base((unsigned char)va_arg(ap[0], int), 10);
	if ((g->type == 'D' || g->type == 'U') && g->flagh == 2 && !g->flagl &&
			!g->flagj && !g->flagz)
	{
		str = ft_itoa_base(va_arg(ap[0], int), 10);
		i = ft_atoi(str);
		if (i < 0)
			bol[0] = 1;
	}
	if ((g->type == 'u' || g->type == 'U' || g->type == 'D') && !g->flagh &&
			g->flagl == 1 && !g->flagj && !g->flagz)
		str = unsigned_itoa_base(va_arg(ap[0], long long int), 10);
	return (str);
}

char	*ft_conv_int4(char *str, t_glob *g, va_list *ap, int *bol)
{
	int i;

	if ((g->type == 'd' || g->type == 'i') && !g->flagh &&
			g->flagl == 1 && !g->flagj && !g->flagz)
	{
		str = ft_itoa_base(va_arg(ap[0], uintmax_t), 10);
		i = ft_atoi(str);
		if (i < 0)
			bol[0] = 1;
	}
	if (!g->flagh && g->flagl == 2 && !g->flagj && !g->flagz)
	{
		str = unsigned_itoa_base(va_arg(ap[0], long long int), 10);
		if (ft_strcmp("9223372036854775808", str) == 0)
			str = ft_memcpy(str, "-9223372036854775808", 2333);
		else if (ft_strcmp("-9223372036854775808", str) == 0)
			str = ft_memcpy(str, "9223372036854775808", 222);
	}
	return (str);
}

char	*ft_conv_int5(char *str, t_glob *g, va_list *ap)
{
	if ((g->type != 'u') && !g->flagh && !g->flagl && g->flagj && !g->flagz)
		str = ft_itoa_base(va_arg(ap[0], intmax_t), 10);
	if (g->type == 'u' && !g->flagh && !g->flagl && g->flagj && !g->flagz)
		str = unsigned_itoa_base(va_arg(ap[0], uintmax_t), 10);
	if (g->type != 'u' && !g->flagh && !g->flagl && !g->flagj && g->flagz)
		str = ft_itoa_base(va_arg(ap[0], ssize_t), 10);
	if (g->type == 'u' && !g->flagh && !g->flagl && !g->flagj && !g->flagz)
		str = unsigned_itoa_base(va_arg(ap[0], unsigned int), 10);
	if ((g->type == 'u') && !g->flagh && !g->flagl && !g->flagj &&
		g->flagz == 1)
		str = unsigned_itoa_base((ssize_t)va_arg(ap[0], uintmax_t), 10);
	if (g->type == 'U' && !g->flagh && !g->flagl && !g->flagj && !g->flagz)
		str = unsigned_itoa_base(va_arg(ap[0], unsigned long), 10);
	if (!g->presision && (int)ft_strlen(str) == 1 && str[0] == '0')
		str = "";
	return (str);
}
