/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:48:08 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/07 12:12:38 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_minus(int size, t_env *env)
{
	int			i;
	int			j;

	i = 0;
	j = ft_strlen(env->quest);
	write(1, env->quest, j);
	while (i < (size - j))
	{
		ft_putchar(' ');
		i++;
	}
	return (i + j);
}

static int		ft_zero(int size, t_env *env)
{
	int			i;
	int			j;

	i = 0;
	j = ft_strlen(env->quest);
	while (i < (size - j))
	{
		ft_putchar('0');
		i++;
	}
	write(1, env->quest, j);
	return (i + j);
}

static int		ft_space(int size, t_env *env)
{
	int			i;
	int			j;

	i = 0;
	j = ft_strlen(env->quest);
	while (i < (size - j))
	{
		ft_putchar(' ');
		i++;
	}
	write(1, env->quest, j);
	return (i + j);
}

int				ft_print_c(t_env *env)
{
	int		i;

	i = 0;
	if (env->size && !env->zero && !env->minus && env->quest)
		i = ft_space(env->size, env);
	else if (env->size && env->zero && !env->minus && env->quest)
		i = ft_zero(env->size, env);
	else if (env->size && env->minus && env->quest)
		i = ft_minus(env->size, env);
	else
	{
		i = ft_strcmp(env->quest, "0") == -48 ? 1 : ft_strlen(env->quest);
		write(1, env->quest, ft_strlen(env->quest));
	}
	return (i);
}
