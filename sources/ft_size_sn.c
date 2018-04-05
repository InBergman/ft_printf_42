/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_sn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:48:08 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/10 03:27:29 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size_two(t_env *env, int i, int j, long long int arg)
{
	env->arg = arg;
	while (i < env->size + j)
	{
		ft_putchar(env->c);
		i++;
	}
	i -= j;
	if (env->plus && arg > 0 && env->c == ' ')
		ft_putchar('+');
	if (env->precision && arg < 0)
	{
		ft_putchar('-');
		env->arg = -arg;
	}
	while (env->precision > intlen(arg))
	{
		ft_putchar('0');
		env->precision--;
	}
	return (i);
}

int			ft_size_sn(long long int arg, t_env *env, int excep)
{
	int		i;
	int		j;

	i = 0;
	if (env->plus || env->space || arg < 0)
		i++;
	if (!env->isprecision)
		env->c = env->zero == 1 ? '0' : ' ';
	else
		env->c = ' ';
	if (env->plus && arg >= 0 && env->c == '0')
		ft_putchar('+');
	else if (env->space && arg >= 0 && !env->plus)
		ft_putchar(' ');
	if ((arg < 0 && env->c == '0'))
	{
		ft_putchar('-');
		arg = -arg;
	}
	i += env->precision > intlen(arg) ? env->precision : intlen(arg);
	j = excep && arg == 0 ? 1 : 0;
	i = ft_size_two(env, i, j, arg);
	if (!excep)
		ft_putnbr_ll(env->arg);
	return (i);
}
