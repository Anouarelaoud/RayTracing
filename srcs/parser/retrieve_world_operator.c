/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_world_operator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:43:18 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/13 00:44:46 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			retrieve_world_operator(t_rt *rt)
{
	int		nb;
	char	*accepted[2];
	char	*required[1];

	accepted[0] = "name";
	accepted[1] = "ambient";
	required[0] = "ambient";
	check_rt_props(rt, accepted, required, (t_point){2, 1});
	rt->xml->obj_list->props = rt->xml->obj_list->head_props;
	nb = rt->xml->obj_list->nb_props;
	while (nb--)
	{
		if (ft_strequ(rt->xml->obj_list->props->key, "ambient"))
			rt->amb = xml_float_or_percentage(rt,
rt->xml->obj_list->props->key, rt->xml->obj_list->props->value);
		if (rt->amb > 1 || rt->amb < 0)
			xml_error(rt, "Unvalid ambient value. (min: 0% | max: 100%)");
		else if (ft_strequ(rt->xml->obj_list->props->key, "name"))
			rt->name = ft_strdup(rt->xml->obj_list->props->value);
		rt->xml->obj_list->props = rt->xml->obj_list->props->next;
	}
}
