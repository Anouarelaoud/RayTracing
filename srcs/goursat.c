/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goursat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 06:11:47 by mderri            #+#    #+#             */
/*   Updated: 2020/11/12 06:11:49 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		intersection_goursat(t_rt *r, t_obj *g)
{
	t_vecteur	x;
	long double	c[5];

	x = sub(r->ray.org, g->pos);
	c[4] = (r->u.x * r->u.x * r->u.x * r->u.x) +
	(r->u.y * r->u.y * r->u.y * r->u.y) + (r->u.z * r->u.z * r->u.z * r->u.z);
	c[3] = 4 * ((r->u.x * r->u.x * r->u.x * x.x) +
	(r->u.y * r->u.y * r->u.y * x.y) + (r->u.z * r->u.z * r->u.z * x.z));
	c[2] = 6 * ((r->u.x * r->u.x * x.x * x.x) +
	(r->u.y * r->u.y * x.y * x.y) + (r->u.z * r->u.z * x.z * x.z));
	c[1] = 4 * ((r->u.x * x.x * x.x * x.x) +
	(r->u.y * x.y * x.y * x.y) + (r->u.z * x.z * x.z * x.z));
	c[0] = (x.x * x.x * x.x * x.x) +
	(x.y * x.y * x.y * x.y) + (x.z * x.z * x.z * x.z) - 1;
	return (distances2(r, c));
}

int		rat_trace_goursat(t_rt *r, t_obj *obj)
{
	if (intersection_goursat(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}
