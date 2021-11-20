/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ux.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 04:54:14 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/11 23:37:34 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	select_object(t_rt *rt, int x, int y)
{
	if (rt->res > 1)
	{
		rt->v2.x = (x - RENDER_X) * rt->res;
		rt->v2.y = (y - RENDER_Y) * rt->res;
	}
	else
	{
		rt->v2.x = (x - RENDER_X) + rt->res;
		rt->v2.y = (y - RENDER_Y) + rt->res;
	}
	make_ray(rt);
	rt->u = normalise(rt->ray.direct);
	rt->dis = MAX;
	if (cast_object(rt))
		rt->selected = rt->obj->parent->head_compos;
	else
		rt->selected = NULL;
	update_ui(rt);
}
