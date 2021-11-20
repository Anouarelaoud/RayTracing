/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 03:09:09 by mderri            #+#    #+#             */
/*   Updated: 2020/11/11 22:47:46 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

long double			intersection_p(t_rt *r, t_obj *p)
{
	long double		t;
	long double		i;

	i = dot(normalise(p->axe), r->u);
	if (fabs((double)(double)i) > MIN)
	{
		t = dot(normalise(p->axe), sub(p->pos, r->ray.org)) / i;
		if (t > MIN && r->dis > t && getcolorfromtexture(r, p, t))
		{
			r->dis = t;
			return (1);
		}
	}
	return (0);
}

int					rat_trace_plane(t_rt *r, t_obj *obj)
{
	if (intersection_p(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}

int					getangleplan(t_obj *plane_temp, t_vecteur p)
{
	plane_temp->txt->um = p.x * 0.01 * (1.0 / plane_temp->txt->hi) +
	plane_temp->txt->x_offset;
	plane_temp->txt->vm = p.z * 0.01 * (1.0 / plane_temp->txt->hi) +
	plane_temp->txt->y_offset;
	if (!plane_temp->txt->coup)
		plane_temp->txt->um -= floor(plane_temp->txt->um);
	else
	{
		plane_temp->txt->um = p.x;
		if (plane_temp->txt->um > 1.0 || plane_temp->txt->um < 0.0)
			return (0);
	}
	if (!plane_temp->txt->coup)
		plane_temp->txt->vm -= floor(plane_temp->txt->vm);
	else
	{
		plane_temp->txt->vm = p.z;
		if (plane_temp->txt->vm > 1.0 || plane_temp->txt->vm < 0.0)
			return (0);
	}
	return (1);
}
