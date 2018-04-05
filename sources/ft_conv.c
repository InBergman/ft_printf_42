/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 19:06:47 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/07 17:30:58 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv(va_list ap, t_env *env, t_tab *tab)
{
	int c;

	c = (int)env->params;
	return (tab->tab_ft_conv[c](ap, env));
}
