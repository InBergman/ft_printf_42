/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:48:08 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/12 14:35:37 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void			init_env(t_env *env)
{
	env->result = 0;
	env->i = 0;
}

int					ft_printf(const char *format, ...)
{
	va_list		ap;
	t_env		env;
	t_tab		tab;

	va_start(ap, format);
	init_env(&env);
	init_tab(&tab);
	while (format[env.i])
	{
		if (format[env.i] != '%' && format[env.i])
		{
			ft_putchar(format[env.i]);
			env.result++;
		}
		else if (format[env.i] == '%' && format[env.i + 1])
		{
			init_flags(&env);
			env.i += 1 + ft_whichflags((char*)(format + env.i + 1), &env);
			env.result += ft_conv(ap, &env, &tab);
		}
		else
			return (env.result);
		env.i++;
	}
	return (env.result);
}
