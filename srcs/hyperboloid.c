/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyperboloid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:32:48 by mderri            #+#    #+#             */
/*   Updated: 2020/03/18 13:46:01 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		intersection_hp(t_rt *r, t_obj *hp)
{
	t_vecteur	param;
	t_vecteur	x;

	hp->axe = normalise(hp->axe);
	x = sub(r->ray.org, hp->pos);
	param.x = ((r->u.x * r->u.x) / (hp->axe.x * hp->axe.x)) +
	((r->u.y * r->u.y) / (hp->axe.y * hp->axe.y)) -
	((r->u.z * r->u.z) / (hp->axe.z * hp->axe.z));
	param.y = ((2 * x.x * r->u.x) / (hp->axe.x * hp->axe.x)) +
	((2 * x.y * r->u.y) / (hp->axe.y * hp->axe.y)) -
	((2 * x.z * r->u.z) / (hp->axe.z * hp->axe.z));
	param.z = ((x.x * x.x) / (hp->axe.x * hp->axe.x)) +
	((x.y * x.y) / (hp->axe.y * hp->axe.y)) -
	((x.z * x.z) / (hp->axe.z * hp->axe.z)) - 1;
	r->delta = param.y * param.y - 4 * param.x * param.z;
	if (r->delta < 0)
		return (0);
	r->sol1 = (-param.y - sqrt(r->delta)) / (2 * param.x);
	r->sol2 = (-param.y + sqrt(r->delta)) / (2 * param.x);
	return (distances(r));
}

int		rat_trace_hyperboloid(t_rt *r, t_obj *obj)
{
	if (intersection_hp(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}
