/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istype_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:48:08 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/12 16:32:49 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_l_s(va_list ap, t_env *env)
{
	wchar_t	*arg;
	int		i;

	i = 0;
	arg = va_arg(ap, wchar_t *);
	if (arg == NULL)
		env->world = NULL;
	else if (arg[0] == 0)
		return (0);
	else if (arg)
	{
		while (arg[i])
		{
			ft_conv_unicode(arg[i], env);
			if (i == 0 && env->quest)
				env->world = ft_strdup(env->quest);
			else
				env->world = ft_strcat(env->world, env->quest);
			i++;
			free(env->quest);
		}
	}
	i = ft_print_s(env);
	return (i);
}

int			istype_s(va_list ap, t_env *env)
{
	char	*arg;
	int		i;

	i = 0;
	if (env->l || env->params == 'S')
	{
		env->world = NULL;
		i = ft_l_s(ap, env);
	}
	else
	{
		arg = va_arg(ap, char *);
		i = ft_print_char_s(arg, env);
	}
	return (i);
}
