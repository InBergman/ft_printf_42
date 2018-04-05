/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o_unsigned_number_bis.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:32:07 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/11 17:36:41 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_minus_bis(char *arg, t_env *env)
{
	int			j;

	j = ft_strlen(arg);
	while (j < env->precision)
	{
		ft_putchar('0');
		j++;
	}
	return (j);
}
