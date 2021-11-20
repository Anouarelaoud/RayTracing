/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:56:14 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/12 18:27:08 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pot(int p)
{
	if (p == 0)
		return (1);
	if (p == 1)
		return (10);
	return (10 * pot(p - 1));
}

static int	ft_len_untill(const char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

long double	ft_atof(const char *str)
{
	long double	result;
	int			i;

	result = (long double)ft_atoi(str);
	i = ft_len_untill(str, '.');
	if (i && str[i])
	{
		if (result >= 0 && str[0] != '-')
			result += ((long double)ft_atoi(str + i + 1))
				/ pot(ft_strlen(str + i + 1));
		else
			result -= ((long double)ft_atoi(str + i + 1))
				/ pot(ft_strlen(str + i + 1));
	}
	return (result);
}
