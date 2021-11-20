/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_float_or_percentage.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 02:12:02 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 02:12:17 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	is_percentage(char *input, size_t len)
{
	if (input[len - 1] != '%')
		return (0);
	if (!isdouble(ft_strsub(input, 0, ft_strlen(input) - 1)))
		return (0);
	return (1);
}

long double	xml_float_or_percentage(t_rt *rt, char *prop, char *input)
{
	size_t		len;
	long double	ret;

	len = ft_strlen(input);
	if (isdouble(input))
	{
		ret = ft_atof(input);
		if (ret < 0)
			xml_error(rt, ft_strjoin(prop, ": value should be positive"));
		return (ret);
	}
	else if (is_percentage(input, len))
	{
		ret = ft_atof(ft_strsub(input, 0, len - 1)) / 100.0;
		if (ret < 0.0)
			xml_error(rt, ft_strjoin(prop, ": value should be positive"));
		return (ret);
	}
	else
		xml_error(rt, ft_strjoin("Expected a float or a percentage value in \
the following property:", prop));
	return (-1);
}
