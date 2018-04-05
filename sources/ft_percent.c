/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:48:08 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/04 15:49:30 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_minus(int size, char c)
{
	int		i;

	i = 0;
	ft_putchar(c);
	while (i < (size - 1))
	{
		ft_putchar(' ');
		i++;
	}
	return (i + 1);
}

static int			ft_zero(int size, char c)
{
	int		i;

	i = 0;
	while (i < (size - 1))
	{
		ft_putchar('0');
		i++;
	}
	ft_putchar(c);
	return (i + 1);
}

static int			ft_space(int size, char c)
{
	int		i;

	i = 0;
	while (i < (size - 1))
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar(c);
	return (i + 1);
}

int					ft_percent(va_list ap, t_env *env)
{
	int		i;

	i = 0;
	if (env->size && !env->zero && !env->minus)
		i = ft_space(env->size, env->params);
	else if (env->size && env->zero && !env->minus)
		i = ft_zero(env->size, env->params);
	else if (env->size && env->minus)
		i = ft_minus(env->size, env->params);
	else
	{
		i = 1;
		ft_putchar(env->params);
	}
	(void)(ap);
	(void)(env);
	return (i);
}
