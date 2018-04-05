/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 13:52:33 by mberedda          #+#    #+#             */
/*   Updated: 2016/05/12 16:33:58 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_strjoin_free(char const *s1, char const *s2, int fe)
{
	int			length;
	int			i;
	int			j;
	char		*str;

	str = NULL;
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
	if (fe & 1)
		free((void*)s1);
	if (fe & 2)
		free((void*)s2);
	return (str);
}

static char			*ft_hexa(unsigned long long int arg, t_env *env)
{
	char						*tmp;
	unsigned long long int		i;
	unsigned long long int		j;

	tmp = NULL;
	i = 10;
	j = (env->params == 'x' || env->params == 'p') ? 'a' : 'A';
	if (arg < 10)
		tmp = ft_ulltoa(arg);
	else if (arg < 16)
	{
		while (i != arg)
			i++;
		tmp = ft_strjoin_c(j + (i - 10));
	}
	return (tmp);
}

char				*ft_conv_hexa(unsigned long long int arg, t_env *env)
{
	char	*dst;
	char	*tmp;
	int		i;

	dst = NULL;
	tmp = NULL;
	dst = ft_strdup("0");
	i = arg ? 1 : 0;
	while (arg != 0)
	{
		tmp = ft_hexa(arg % 16, env);
		dst = ft_strjoin_free(tmp, dst, 2);
		arg /= 16;
	}
	if (i)
		dst = ft_strsub(dst, 0, (ft_strlen(dst) - 1));
	if ((i && env->sharp && env->params == 'x') || env->params == 'p')
		dst = ft_strjoin("0x", dst);
	else if (i && env->sharp && env->params == 'X')
		dst = ft_strjoin("0X", dst);
	return (dst);
}
