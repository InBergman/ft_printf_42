/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:48:08 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/12 17:03:54 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ulltoa(unsigned long long int arg)
{
	char						*dst;
	int							i;
	unsigned long long int		value;

	dst = NULL;
	if (arg == 0)
		return ("0");
	i = uintlen(arg) + 1;
	dst = (char *)malloc(sizeof(char) * (i));
	if (!dst)
		return (NULL);
	dst[i - 1] = '\0';
	i = i - 2;
	while (arg > 9)
	{
		value = arg % 10;
		dst[i] = value + '0';
		arg = (arg / 10);
		i--;
	}
	if (arg <= 9)
		dst[i] = arg + '0';
	return (dst);
}
