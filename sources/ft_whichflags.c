/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whichflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 15:00:42 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/10 01:47:15 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_size_options(char *s, t_env *env)
{
	int		i;

	i = 0;
	if (s[i] == 'h' && s[i + 1] != 'h')
		env->h = 1;
	else if (s[i] == 'h' && s[i + 1] == 'h')
	{
		env->hh = 1;
		i++;
	}
	else if (s[i] == 'l' && s[i + 1] != 'l')
		env->l = 1;
	else if (s[i] == 'l' && s[i + 1] == 'l')
	{
		env->ll = 1;
		i++;
	}
	else if (s[i] == 'j')
		env->j = 1;
	else if (s[i] == 'z')
		env->z = 1;
	return (i);
}

static int			ft_precision(char *s, t_env *env)
{
	int		i;

	i = 0;
	env->isprecision = 1;
	while (s[i] == '.')
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
		{
			while (ft_isdigit(s[i]) && s[i])
			{
				env->precision = env->precision * 10 + (s[i] - '0');
				i++;
			}
		}
		else
			env->precision = 0;
		return (i - 1);
	}
	return (i--);
}

static int			ft_width(char *s, t_env *env)
{
	int		i;

	i = 0;
	if (s[i])
	{
		while (s[i] == '0')
		{
			env->zero = 1;
			i++;
		}
		while (ft_isdigit(s[i]))
		{
			env->size = env->size * 10 + (s[i] - '0');
			i++;
		}
	}
	else if (!s[i])
		i = 1;
	return (i - 1);
}

static void			ft_options(char c, t_env *env)
{
	if (c == '-')
		env->minus = 1;
	else if (c == '+')
		env->plus = 1;
	else if (c == ' ')
		env->space = 1;
	else if (c == '#')
		env->sharp = 1;
}

int					ft_whichflags(char *format, t_env *env)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '#' || format[i] == '-' || format[i] == '+' ||
				format[i] == ' ')
			ft_options(format[i], env);
		else if (ft_isdigit(format[i]) && env->isprecision == 0)
			i += ft_width(&format[i], env);
		else if (format[i] == '.')
			i += ft_precision(&format[i], env);
		else if (format[i] == 'h' || format[i] == 'l' || format[i] == 'j'
				|| format[i] == 'z')
			i += ft_size_options(&format[i], env);
		else
		{
			env->params = format[i];
			return (i);
		}
		i++;
	}
	return (i);
}
