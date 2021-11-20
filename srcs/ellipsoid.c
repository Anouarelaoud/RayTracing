/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:31:19 by mderri            #+#    #+#             */
/*   Updated: 2020/03/22 09:34:09 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				intersection_ell(t_rt *r, t_obj *ell)
{
	t_vecteur	param;
	t_vecteur	x;

	x = sub(r->ray.org, ell->pos);
	param.x = ((r->u.x * r->u.x) / (ell->axe.x * ell->axe.x)) +
	((r->u.y * r->u.y) / (ell->axe.y * ell->axe.y)) +
	((r->u.z * r->u.z) / (ell->axe.z * ell->axe.z));
	param.y = ((2 * x.x * r->u.x) / (ell->axe.x * ell->axe.x)) +
	((2 * x.y * r->u.y) / (ell->axe.y * ell->axe.y)) +
	((2 * x.z * r->u.z) / (ell->axe.z * ell->axe.z));
	param.z = ((x.x * x.x) / (ell->axe.x * ell->axe.x)) +
	((x.y * x.y) / (ell->axe.y * ell->axe.y)) +
	((x.z * x.z) / (ell->axe.z * ell->axe.z)) - 1;
	r->delta = param.y * param.y - 4 * param.x * param.z;
	if (r->delta < 0)
		return (0);
	r->sol1 = (-param.y - sqrt(r->delta)) / (2 * param.x);
	r->sol2 = (-param.y + sqrt(r->delta)) / (2 * param.x);
	return (distances(r));
}

int				rat_trace_ellipsoid(t_rt *r, t_obj *obj)
{
	if (intersection_ell(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}
