/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_screen_operator.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:42:26 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/13 00:42:50 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			retrieve_screen_operator(t_rt *rt)
{
	int	nb;

	rt->res = 1;
	rt->xml->obj_list->props = rt->xml->obj_list->head_props;
	nb = rt->xml->obj_list->nb_props;
	while (nb--)
	{
		if (ft_strequ(rt->xml->obj_list->props->key, "resolution"))
		{
			rt->res = xml_float_or_percentage(rt,
rt->xml->obj_list->props->key, rt->xml->obj_list->props->value);
			if (rt->res != .25 && rt->res != .5 && rt->res != 1 &&
rt->res != 2)
				xml_error(rt, "Resolution value is not accepted.\n\
Accepted values: 25%, 50%, 100%, 200%");
		}
		rt->xml->obj_list->props = rt->xml->obj_list->props->next;
	}
}
