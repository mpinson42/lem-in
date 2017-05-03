/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:39:54 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/10 16:50:14 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conv(char *str, int base)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' &&
					str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F')))
	{
		nb = nb * base;
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			nb = nb + (str[i] - 'a') + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			nb = nb + (str[i] - 'A') + 10;
		i++;
	}
	return (nb);
}

int	ft_atoi_base(char *str, int base)
{
	int i;
	int neg;

	neg = 1;
	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == ' ' ||
				str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	return (ft_conv(&str[i], base) * neg);
}
