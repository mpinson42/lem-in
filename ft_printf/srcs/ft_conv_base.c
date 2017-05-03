/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:39:05 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 17:39:09 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_conv_base1(char *str, t_glob *g, va_list *ap)
{
	if ((g->type == 'o') && !g->flagh && !g->flagl && !g->flagj && !g->flagz)
		str = unsigned_itoa_base(va_arg(ap[0], unsigned int), 8);
	if ((g->type == 'O') && !g->flagh && !g->flagl && !g->flagj && !g->flagz)
		str = unsigned_itoa_base(va_arg(ap[0], uintmax_t), 8);
	if (g->type == 'b')
		str = ft_itoa_base(va_arg(ap[0], int), 2);
	if ((g->type == 'o' || g->type == 'O') && !g->flagh && !g->flagl &&
			g->flagj && !g->flagz)
		str = unsigned_itoa_base(va_arg(ap[0], uintmax_t), 8);
	if ((g->type == 'o' || g->type == 'O') && !g->flagh && !g->flagl &&
			!g->flagj && g->flagz)
		str = unsigned_itoa_base(va_arg(ap[0], ssize_t), 8);
	if ((g->type == 'o' || g->type == 'O') && !g->flagh && g->flagl == 1 &&
			!g->flagj && !g->flagz)
		str = unsigned_itoa_base(va_arg(ap[0], long int), 8);
	if ((g->type == 'o' || g->type == 'O') && g->flagh == 1 && !g->flagl &&
			!g->flagj && !g->flagz)
		str = unsigned_itoa_base((unsigned short int)va_arg(ap[0], int), 8);
	if ((g->type == 'O') && g->flagh == 2 && !g->flagl && !g->flagj &&
			!g->flagz)
		str = unsigned_itoa_base(va_arg(ap[0], unsigned int), 8);
	if ((g->type == 'x' || g->type == 'X') && g->flagh == 1 && !g->flagl &&
			!g->flagj && !g->flagz)
		str = unsigned_itoa_base(va_arg(ap[0], int), 16);
	return (str);
}

char	*ft_conv_base2(char *str, va_list *ap, t_glob *g)
{
	int test;

	test = 0;
	if ((g->type == 'o') && g->flagh == 2 && !g->flagl && !g->flagj &&
			!g->flagz)
		str = unsigned_itoa_base((unsigned char)va_arg(ap[0], int), 8);
	if ((g->type == 'o') && !g->flagh && g->flagl == 2 && !g->flagj &&
			!g->flagz)
	{
		str = unsigned_itoa_base(va_arg(ap[0], long long int), 8);
		test = ft_atoi(str);
		if (ft_strcmp("9223372036854775808", str) == 0)
			str = ft_memcpy(str, "-9223372036854775808", 2333);
		else if (ft_strcmp("-9223372036854775808", str) == 0)
			str = ft_memcpy(str, "9223372036854775808", 222);
	}
	if ((g->type == 'O') && !g->flagh && g->flagl == 2 && !g->flagj &&
			!g->flagz)
		str = unsigned_itoa_base(va_arg(ap[0], long long int), 8);
	return (str);
}

char	*ft_conv_base3(char *str, va_list *ap, t_glob *g)
{
	int test;

	test = 0;
	if ((g->type == 'x' || g->type == 'X') && !g->flagh && !g->flagl &&
			!g->flagj && g->flagz)
		str = unsigned_itoa_base(va_arg(ap[0], ssize_t), 16);
	if ((g->type == 'x' || g->type == 'X') && !g->flagh && !g->flagl &&
			!g->flagj && !g->flagz)
	{
		test = va_arg(ap[0], int);
		if (test < 0)
			str = ft_strsub(unsigned_itoa_base(test, 16), 8, 8);
		else
			str = ft_itoa_base(test, 16);
	}
	if ((g->type == 'x' || g->type == 'X') && g->flagh == 2 && !g->flagl &&
			!g->flagj && !g->flagz)
	{
		test = va_arg(ap[0], unsigned int);
		if (test > 255)
			test = 0 + (test - 255) - 1;
		str = unsigned_itoa_base(test, 16);
	}
	return (str);
}

char	*ft_conv_base4(char *str, va_list *ap, t_glob *g)
{
	if ((g->type == 'x' || g->type == 'X') && !g->flagh && g->flagl == 1 &&
			!g->flagj && !g->flagz)
		str = unsigned_itoa_base(va_arg(ap[0], long int), 16);
	if ((g->type == 'x' || g->type == 'X') && !g->flagh && !g->flagl &&
			g->flagj == 1 && !g->flagz)
		str = unsigned_itoa_base(va_arg(ap[0], uintmax_t), 16);
	if ((g->type == 'x' || g->type == 'X') && !g->flagh && g->flagl == 2 &&
			!g->flagj && !g->flagz)
	{
		str = unsigned_itoa_base(va_arg(ap[0], long long int), 16);
		if (ft_strcmp("9223372036854775808", str) == 0)
			str = ft_memcpy(str, "-9223372036854775808", 2333);
		else if (ft_strcmp("-9223372036854775808", str) == 0)
			str = ft_memcpy(str, "9223372036854775808", 222);
	}
	return (str);
}
