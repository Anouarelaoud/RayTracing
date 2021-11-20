/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 02:12:42 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 02:13:01 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			xml_int(t_rt *rt, char *prop, char *input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			xml_error(rt, ft_strjoin("Expected an integer value in the \
following property: ", prop));
		i++;
	}
	i = ft_atoi(input);
	if (i < 0)
		xml_error(rt, ft_strjoin(prop, ": value should be positive"));
	return (ft_atoi(input));
}
