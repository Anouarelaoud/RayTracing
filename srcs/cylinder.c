/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 09:04:42 by mderri            #+#    #+#             */
/*   Updated: 2020/11/12 01:06:44 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				intersection_c(t_rt *r, t_obj *c)
{
	t_vecteur	param;
	t_vecteur	newv;

	newv = c->axe;
	param.x = dot(r->u, r->u) - (dot(r->u, normalise(newv)) * dot(r->u,
	normalise(newv)));
	param.y = 2 * (dot(r->u, sub(r->ray.org, c->pos)) - (dot(r->u,
	normalise(newv)) * dot(normalise(newv), sub(r->ray.org, c->pos))));
	param.z = module(sub(r->ray.org, c->pos)) * module(sub(r->ray.org, c->pos))
	- (dot(sub(r->ray.org, c->pos), normalise(newv)) * dot(sub(r->ray.org,
	c->pos), normalise(newv))) - c->k * c->k;
	r->delta = param.y * param.y - 4 * param.x * param.z;
	if (r->delta < 0)
		return (0);
	r->sol1 = (-param.y - sqrt(r->delta)) / (2 * param.x);
	r->sol2 = (-param.y + sqrt(r->delta)) / (2 * param.x);
	return (distances_tex(r, c));
}

int				rat_trace_cylinder(t_rt *r, t_obj *obj)
{
	if (intersection_c(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}

int				getanglecylinder(t_obj *plane_temp, t_vecteur p)
{
	plane_temp->txt->um = fmod((atan2(p.x, p.z) / (2.0 * M_PI)),
	1.0) + plane_temp->txt->x_offset;
	plane_temp->txt->vm = fmod((p.y + 5.0 / 2) / 5.0, plane_temp->txt->hi)
	+ plane_temp->txt->y_offset;
	plane_temp->txt->um -= floor(plane_temp->txt->um);
	if (!plane_temp->txt->coup)
		plane_temp->txt->um -= floor(plane_temp->txt->um);
	else
	{
		plane_temp->txt->vm = (p.y + 5.0 / 2) / 5.0;
		if (plane_temp->txt->vm > 1.0 || plane_temp->txt->vm < 0.0)
			return (0);
	}
	return (1);
}
