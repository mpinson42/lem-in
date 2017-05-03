/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 18:00:23 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 18:00:25 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uni_putstr(wchar_t *str)
{
	int i;
	int count;
	int test;

	count = 0;
	i = 0;
	while (str[i])
	{
		if ((test = ft_uni_putchar(str[i])) == -1)
			return (-1);
		count = count + test;
		i++;
	}
	return (count);
}
