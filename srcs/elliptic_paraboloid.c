/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elliptic_paraboloid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:31:35 by mderri            #+#    #+#             */
/*   Updated: 2020/03/18 13:43:10 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				intersection_pb(t_rt *r, t_obj *p)
{
	t_vecteur	x;
	t_vecteur	param;

	x = sub(r->ray.org, p->pos);
	param.x = dot(r->u, r->u) - dot(r->u, p->axe) *
	dot(r->u, p->axe);
	param.y = 2 * (dot(r->u, x) - dot(r->u, p->axe) *
	(dot(x, p->axe) + 2 * p->k));
	param.z = dot(x, x) - dot(x, p->axe) *
	(dot(x, p->axe) + 4 * p->k);
	r->delta = param.y * param.y - 4 * param.x * param.z;
	if (r->delta < 0)
		return (0);
	r->sol1 = (-param.y - sqrt(r->delta)) / (2 * param.x);
	r->sol2 = (-param.y + sqrt(r->delta)) / (2 * param.x);
	return (distances(r));
}

int				rat_trace_paraboloid(t_rt *r, t_obj *obj)
{
	if (intersection_pb(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}
