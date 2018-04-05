/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istype_o_jz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:48:08 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/05 15:04:24 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int		istype_o_jz(va_list ap, t_env *env)
{
	unsigned long long int	arg;

	arg = 0;
	if (env->j)
	{
		arg = (unsigned long long int)va_arg(ap, uintmax_t);
	}
	else if (env->z)
	{
		arg = va_arg(ap, size_t);
		arg = (unsigned long long int)arg;
	}
	return (arg);
}
