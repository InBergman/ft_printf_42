/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istype_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 18:10:04 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/12 17:54:43 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long int	ft_ll_signed(va_list ap)
{
	unsigned long long int	arg;

	arg = va_arg(ap, unsigned long long int);
	return (arg);
}

static unsigned long int		ft_l_signed(va_list ap, t_env *env)
{
	unsigned long int	arg;
	void				*parg;

	parg = NULL;
	if (env->params == 'p')
	{
		parg = va_arg(ap, void *);
		arg = (unsigned long int)parg;
	}
	else
		arg = va_arg(ap, unsigned long int);
	return (arg);
}

static unsigned char			ft_hh_signed(va_list ap)
{
	unsigned char			arg;

	arg = va_arg(ap, unsigned int);
	return (arg);
}

static unsigned short int		ft_h_signed(va_list ap)
{
	unsigned short arg;

	arg = va_arg(ap, unsigned int);
	return (arg);
}

int								istype_x(va_list ap, t_env *env)
{
	unsigned long long int	arg;
	char					*dst;
	int						i;

	i = 0;
	if (env->ll && env->params != 'p')
		arg = ft_ll_signed(ap);
	else if (env->l || env->params == 'p')
		arg = (unsigned long long int)ft_l_signed(ap, env);
	else if (env->hh)
		arg = (unsigned long long int)ft_hh_signed(ap);
	else if (env->h)
		arg = (unsigned long long int)ft_h_signed(ap);
	else if (env->j || env->z)
		arg = istype_o_jz(ap, env);
	else
	{
		arg = va_arg(ap, unsigned int);
		arg = (unsigned long long int)arg;
	}
	dst = ft_conv_hexa(arg, env);
	i = ft_print_unsigned_number(dst, env);
	free(dst);
	return (i);
}
