/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istype_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:48:08 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/12 17:05:05 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long int	ft_ll_signed(va_list ap)
{
	unsigned long long int	arg;

	arg = va_arg(ap, unsigned long long int);
	return (arg);
}

static unsigned long int		ft_l_signed(va_list ap)
{
	unsigned long int	arg;

	arg = va_arg(ap, unsigned long int);
	return (arg);
}

static unsigned char			ft_hh_signed(va_list ap)
{
	unsigned char	arg;

	arg = va_arg(ap, unsigned int);
	return (arg);
}

static unsigned short			ft_h_signed(va_list ap)
{
	unsigned short	arg;

	arg = va_arg(ap, unsigned int);
	return (arg);
}

int								istype_u(va_list ap, t_env *env)
{
	unsigned long long int	arg;
	char					*arg2;
	int						i;

	i = 0;
	if (env->ll && env->params != 'U')
		arg = ft_ll_signed(ap);
	else if (env->l || env->params == 'U')
		arg = (unsigned long long int)ft_l_signed(ap);
	else if (env->hh)
		arg = (unsigned long long int)ft_hh_signed(ap);
	else if (env->h)
		arg = (unsigned long long int)ft_h_signed(ap);
	else if (env->j || env->z)
		arg = istype_o_jz(ap, env);
	else
		arg = (unsigned long long int)va_arg(ap, unsigned int);
	arg2 = ft_ulltoa(arg);
	i = ft_print_unsigned_number(arg2, env);
	return (i);
}
