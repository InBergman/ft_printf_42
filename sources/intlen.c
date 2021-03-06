/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:48:08 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/11 17:20:20 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			intlen(long long int nb)
{
	int		i;

	i = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = -nb;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
