/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:48:08 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/12 16:12:27 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_conv_unicode(wchar_t arg, t_env *env)
{
	env->quest = ft_strnew(5);
	if (arg < 0x80)
		env->quest[0] = ((arg >> 0) & 0x7F) | 0x00;
	else if (arg < 0x0800)
	{
		env->quest[0] = ((arg >> 6) & 0x1F) | 0xC0;
		env->quest[1] = ((arg >> 0) & 0x3F) | 0x80;
	}
	else if (arg < 0x010000)
	{
		env->quest[0] = ((arg >> 12) & 0x0F) | 0xE0;
		env->quest[1] = ((arg >> 6) & 0x3F) | 0x80;
		env->quest[2] = ((arg >> 0) & 0x3F) | 0x80;
	}
	else if (arg < 0x110000)
	{
		env->quest[0] = ((arg >> 18) & 0x07) | 0xF0;
		env->quest[1] = ((arg >> 12) & 0x3F) | 0x80;
		env->quest[2] = ((arg >> 6) & 0x3F) | 0x80;
		env->quest[3] = ((arg >> 0) & 0x3F) | 0x80;
	}
}
