/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 15:34:15 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 18:11:51 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft.h"
# include <unistd.h>
# include <inttypes.h>

typedef struct	s_glob
{
	int					flag_htag;
	int					flag_largeur;
	int					presision;
	int					flag_0;
	int					flag_neg;
	int					flag_more;
	int					flag_space;
	int					flagl;
	int					flagh;
	int					flagj;
	int					flagz;
	char				type;
}				t_glob;

int				ft_base(va_list *ap, t_glob *g);
int				ft_unichar(va_list *ap, t_glob *g);
int				ft_char(va_list *ap, t_glob *g);
int				ft_int(va_list *ap, t_glob *g);
int				ft_uni_string(va_list *ap, t_glob *g);
int				ft_string(va_list *ap, t_glob *g);
int				ft_lecture(int *i, char *str, va_list *ap);
int				ft_choise(va_list *ap, t_glob *g);
int				ft_printf(char *str, ...);
char			*ft_conv_int5(char *str, t_glob *g, va_list *ap);
char			*ft_conv_int4(char *str, t_glob *g, va_list *ap, int *bol);
char			*ft_conv_int3(char *str, t_glob *g, va_list *ap, int *bol);
char			*ft_conv_int2(char *str, t_glob *g, va_list *ap, int *bol);
char			*ft_conv_int1(char *str, t_glob *g, va_list *ap, int *bol);
char			*ft_largeur_int5(char *str, t_glob *g, int bol);
char			*ft_largeur_int4(char *str, t_glob *g);
char			*ft_largeur_int3(char *str, t_glob *g);
char			*ft_largeur_int2(char *str, t_glob *g, int bol);
char			*ft_largeur_int1(char *str, t_glob *g, int bol);
char			*ft_largeur_int8(char *str, t_glob *g, int bol);
char			*ft_largeur_int7(char *str, t_glob *g, int bol);
char			*ft_largeur_int6(char *str, t_glob *g, int bol);
char			*ft_conv_base1(char *str, t_glob *g, va_list *ap);
char			*ft_conv_base2(char *str, va_list *ap, t_glob *g);
char			*ft_conv_base3(char *str, va_list *ap, t_glob *g);
char			*ft_conv_base4(char *str, va_list *ap, t_glob *g);
int				ft_pointeur(va_list *ap, t_glob *g);
char			*ft_largeur_ptr(char *ptr, int tmp, char *str, t_glob *g);
int				ft_pourcent(t_glob *g);
int				ft_largeur(int i, t_glob *g, char c);
char			*ft_largeur_str3(char *str, t_glob *g, int bol);
char			*ft_largeur_str4(char *str, t_glob *g, int bol);
char			*ft_largeur_str5(char *str, t_glob *g, int bol);
char			*ft_largeur_str1(char *str, t_glob *g);
char			*ft_largeur_str2(char *str, t_glob *g);
char			*ft_presision_str1(char *str, t_glob *g, int bol);
char			*ft_presision_str2(char *str, t_glob *g, int bol);
char			*ft_flaeg_more_space_str1(char *str, t_glob *g, int bol);
char			*ft_flaeg_more_space_str2(char *str, t_glob *g, int bol);
wchar_t			*ft_largeur_uni_5(wchar_t *str, t_glob *g, int bol);
wchar_t			*ft_largeur_uni_4(wchar_t *str, t_glob *g, int bol);
wchar_t			*ft_largeur_uni_3(wchar_t *str, t_glob *g, int bol);
wchar_t			*ft_largeur_uni_1(wchar_t *str, t_glob *g);
wchar_t			*ft_largeur_uni_2(wchar_t *str, t_glob *g);
wchar_t			*ft_flag_more_space_uni1(wchar_t *str, t_glob *g, int bol);
wchar_t			*ft_flag_more_space_uni2(wchar_t *str, t_glob *g, int bol);
wchar_t			*ft_presision_uni2(wchar_t *str, t_glob *g, int bol);
wchar_t			*ft_presision_uni1(wchar_t *str, t_glob *g, int bol);
void			ft_init(t_glob *g);
char			*ft_strjoin_char2(char *str, char c);
int				ft_trie(t_glob *g, char *str, int *i);
void			ft_assigne(char *str, int *i, t_glob *g, int *dot);

#endif
