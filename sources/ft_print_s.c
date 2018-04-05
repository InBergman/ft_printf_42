/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:48:08 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/12 16:32:01 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_precision_null(char *arg, int j)
{
	int		l;
	int		k;

	l = 0;
	k = 0;
	while (l < j)
	{
		k += ft_wchar_len(arg[l]);
		if (k <= j)
		{
			write(1, &arg[l], (size_t)ft_wchar_len(arg[l]));
			l += ft_wchar_len(arg[l]);
		}
		else
			break ;
	}
	return (l);
}

static int	ft_no_minus(t_env *env, char *arg, char *c, int j)
{
	int i;

	i = 0;
	if (env->size)
		j = env->isprecision ? (env->size - env->precision) : (env->size - j);
	else
		j = 0;
	if (env->size)
		i += ft_size_arg_null(i, c, j);
	if (env->precision < (int)ft_strlen(arg))
		i += ft_precision_null(arg, env->precision);
	if (!env->isprecision)
	{
		write(1, arg, (int)ft_strlen(arg));
		i += (int)ft_strlen(arg);
	}
	return (i);
}

static int	ft_arg_null(char *arg, t_env *env, int i)
{
	char	*c;
	int		j;

	c = env->zero ? ft_cs('0') : ft_cs(' ');
	j = 6;
	if (env->isprecision)
		env->isprecision = env->precision < 6 ? 1 : 0;
	if (!arg)
		arg = ft_strdup("(null)");
	if (env->minus)
	{
		c = ft_cs(' ');
		if (env->isprecision)
			i += ft_precision_null(arg, env->precision);
		else
		{
			i = ft_strlen(arg);
			write(1, arg, i);
		}
		if (env->size)
			i = ft_size_arg_null(i, c, env->size);
	}
	else
		i += ft_no_minus(env, arg, c, j);
	return (i);
}

static int	ft_arg(char *arg, t_env *env, int i)
{
	char	*c;

	c = env->zero ? ft_cs('0') : ft_cs(' ');
	if (env->isprecision)
		env->isprecision = (env->precision < ((int)ft_strlen(arg))) ? 1 : 0;
	if (env->minus)
	{
		c = ft_cs(' ');
		if (env->isprecision)
			i += ft_precision_null(arg, env->precision);
		else
		{
			i = (int)ft_strlen(arg);
			write(1, arg, i);
		}
		if (env->size)
			i = ft_size_arg_null(i, c, env->size);
	}
	else
		i += ft_no_minus(env, arg, c, (int)ft_strlen(arg));
	return (i);
}

int			ft_print_s(t_env *env)
{
	int i;

	i = 0;
	if (!env->world)
		i += ft_arg_null(env->world, env, i);
	else if (env->size || env->isprecision)
		i += ft_arg(env->world, env, i);
	else
	{
		i = (int)ft_strlen(env->world);
		write(1, env->world, i);
	}
	return (i);
}
