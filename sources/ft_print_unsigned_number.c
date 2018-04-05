/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_number.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:48:08 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/07 18:14:34 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size_precision(char *arg, int i, t_env *env, char c)
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
	int		j;
	char	c;

	i = 0;
	if (!env->isprecision)
		c = env->zero == 1 ? '0' : ' ';
	else
		c = ' ';
	i = excep ? 0 : ft_strlen(arg);
	if ((env->sharp || env->params == 'p') && c == '0' && !excep)
		ft_putstr_n(arg, 0, 2);
	j = env->precision > i ? env->precision - i : 0;
	i = ft_size_precision(arg, i, env, c);
	if ((env->sharp || env->params == 'p') && c == '0' && !excep)
		ft_putstr_n(arg, 2, ft_strlen(arg));
	else if (!excep)
		ft_putstr(arg);
	return (i + j);
}

static int	ft_precision(char *arg, t_env *env, int excep)
{
	int i;
	int a;

	i = 0;
	a = ft_strlen(arg);
	i = (env->sharp || env->params == 'p') ? (a - 2) : a;
	if (excep && !env->sharp)
		i = 2;
	if ((env->sharp && !excep) || env->params == 'p')
		ft_putstr_n(arg, 0, 2);
	while (i < env->precision && (env->sharp + excep) != 2)
	{
		ft_putchar('0');
		i++;
	}
	i = (env->sharp || env->params == 'p') && !excep ? i + 2 : i;
	if ((env->sharp || env->params == 'p') && !excep)
		ft_putstr_n(arg, 2, a);
	else if (!(ft_strcmp("0", arg)))
		return (0);
	else if (!excep)
		ft_putstr(arg);
	return (i);
}

static int	ft_minus(char *arg, t_env *env, int excep)
{
	int i;

	i = 0;
	if (!excep)
		ft_putstr(arg);
	i += ft_strlen(arg);
	if (env->size)
	{
		while (i < env->size)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (i);
}

int			ft_print_unsigned_number(char *arg, t_env *env)
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
