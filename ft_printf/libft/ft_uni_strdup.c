/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 13:50:18 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/23 13:50:20 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_uni_strdup(char *src)
{
	wchar_t	*str;
	size_t	i;

	if (src == NULL)
		return (NULL);
	i = 0;
	if (!(str = (wchar_t*)malloc(sizeof(wchar_t) * ft_strlen(src) + 1)))
		return (NULL);
	while (i < ft_strlen(src))
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
