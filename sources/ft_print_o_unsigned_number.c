/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o_unsigned_number.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:48:08 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/11 17:35:56 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size_precision(t_env *env, char *arg, int i, char c)
{
	int j;

	j = env->precision > i ? env->precision - i : 0;
	while (i < env->size - j)
	{
		ft_putchar(c);
		i++;
	}
	while (env->precision > (int)ft_strlen(arg))
	{
		ft_putchar('0');
		env->precision--;
	}
	return (i);
}

static int	ft_size(char *arg, t_env *env, int excep)
{
	int		i;
	char	c;
	int		j;

	i = 0;
	if (!env->isprecision)
		c = env->zero == 1 ? '0' : ' ';
	else
		c = ' ';
	i = excep ? 0 : ft_strlen(arg);
	if ((env->sharp || env->params == 'p') && c == '0' && !excep)
		ft_putstr_n(arg, 0, 2);
	j = env->precision > i ? env->precision - i : 0;
	i = ft_size_precision(env, arg, i, c);
	if ((env->sharp || env->params == 'p') && c == '0' && !excep)
		ft_putstr_n(arg, 2, ft_strlen(arg));
	else if (!(ft_strcmp("0", arg)))
		return (i);
	else
		ft_putstr(arg);
	return (i + j);
}

static int	ft_precision(char *arg, t_env *env, int excep)
{
	int i;
	int a;

	i = 0;
	a = ft_strlen(arg);
	i = (env->sharp || env->params == 'p') ? (a - 1) : a;
	if ((env->sharp || env->params == 'p') && !excep)
		ft_putstr_n(arg, 0, 1);
	while (i < env->precision - env->sharp)
	{
		ft_putchar('0');
		i++;
	}
	i = env->sharp ? 1 + i : i;
	if ((env->sharp || env->params == 'p') && !excep)
		ft_putstr_n(arg, 1, a);
	else if (!(ft_strcmp("0", arg)) && !env->sharp)
		return (0);
	else if (!excep || env->precision < (int)ft_strlen(arg))
		ft_putstr(arg);
	else if (excep && env->sharp && !(ft_strcmp("0", arg)))
		ft_putstr(arg);
	return (i);
}

static int	ft_minus(char *arg, t_env *env, int excep)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (env->isprecision)
		j = ft_minus_bis(arg, env);
	if (!excep)
		ft_putstr(arg);
	i = j ? -1 : (int)ft_strlen(arg);
	if (env->size)
	{
		if (env->isprecision)
		{
			env->size--;
			i += env->precision + 1;
		}
		while ((env->size - ft_strlen(arg)) != 0)
		{
			ft_putchar(' ');
			env->size--;
			i++;
		}
	}
	return (i);
}

int			ft_print_o_unsigned_number(char *arg, t_env *env)
{
	int i;
	int excep;

	i = 0;
	excep = (env->isprecision && env->precision == 0) ? 1 : 0;
	if (env->minus && ((env->precision < env->size && env->isprecision)\
			|| !env->precision))
		i += ft_minus(arg, env, excep);
	else if (env->isprecision && (env->precision >= env->size || !env->size))
		i += ft_precision(arg, env, excep);
	else if (env->size)
		i += ft_size(arg, env, excep);
	else
	{
		if (!excep)
		{
			ft_putstr(arg);
			i = ft_strlen(arg);
		}
	}
	return (i);
}
