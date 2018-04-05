/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:48:08 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/12 16:33:25 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_strjoin_free(char const *s1, char const *s2, int fre)
{
	int			length;
	int			i;
	int			j;
	char		*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	length = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	if (fre & 1)
		free((void*)s1);
	if (fre & 2)
		free((void*)s2);
	return (str);
}

char				*ft_conv_octal(unsigned long long int arg, t_env *env)
{
	char	*dst;
	int		i;

	dst = ft_strdup("0");
	i = arg ? 1 : 0;
	while (arg != 0)
	{
		dst = ft_strjoin_free(ft_ulltoa((arg % 8)), dst, 2);
		arg /= 8;
	}
	if (i)
		dst = ft_strsub(dst, 0, (ft_strlen(dst) - 1));
	if (i && env->sharp)
		dst = ft_strjoin_free("0", dst, 2);
	return (dst);
}
