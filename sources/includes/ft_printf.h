/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 15:28:28 by alaulom           #+#    #+#             */
/*   Updated: 2016/05/12 13:24:49 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../sources/libft/includes/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <wchar.h>
# include <limits.h>
# include <stdint.h>

typedef struct			s_env
{
	int					minus;
	int					plus;
	int					sharp;
	int					zero;
	int					space;
	int					precision;
	int					isprecision;
	int					h;
	int					hh;
	int					l;
	int					ll;
	int					j;
	int					z;
	int					size;
	int					per_cent;
	char				params;
	char				*quest;
	char				*world;
	char				c;
	int					result;
	int					i;
	long long int		arg;
}						t_env;

typedef struct			s_tab
{
	int					(*tab_ft_conv[126])(va_list ap, t_env *env);
}						t_tab;

int						ft_printf(const char *format, ...);
void					init_flags(t_env *env);
void					init_tab(t_tab *tab);
int						ft_whichflags(char *format, t_env *env);
int						ft_percent(va_list ap, t_env *env);
int						istype_c(va_list ap, t_env *env);
void					ft_conv_unicode(wchar_t arg, t_env *env);
int						ft_print_c(t_env *env);
int						ft_print_char_c(char arg, t_env *env);
long long int			istype_d_jz(va_list ap, t_env *env);
int						istype_d(va_list ap, t_env *env);
int						ft_print_signed_number(long long int arg, t_env *env);
int						intlen(long long int nb);
void					ft_putnbr_ll(long long int nb);
int						istype_s(va_list ap, t_env *env);
int						ft_print_char_s(char *arg, t_env *env);
int						ft_size_arg_null_s(int i, char c, int j);
int						ft_print_s(t_env *env);
char					*ft_cs(wchar_t arg);
int						ft_size_arg_null(int i, char *c, int j);
int						ft_wchar_len(wchar_t arg);
int						istype_o(va_list ap, t_env *env);
int						ft_print_o_unsigned_number(char *arg, t_env *env);
void					ft_putstr_n(char *s, int start, int len);
char					*ft_conv_octal(unsigned long long int arg, t_env *env);
char					*ft_ulltoa(unsigned long long int arg);
int						uintlen(unsigned long long int n);
unsigned long long int	istype_o_jz(va_list ap, t_env *env);
int						istype_x(va_list ap, t_env *env);
char					*ft_conv_hexa(unsigned long long int arg, t_env *env);
int						ft_print_unsigned_number(char *arg, t_env *env);
int						istype_u(va_list ap, t_env *env);
char					*ft_strjoin_c(char c);
int						ft_size_sn(long long int arg, t_env *env, int excep);
int						ft_conv(va_list ap, t_env *env, t_tab *tab);

#endif
