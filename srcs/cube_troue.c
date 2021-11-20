/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_troue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 06:53:44 by mderri            #+#    #+#             */
/*   Updated: 2020/03/18 13:18:54 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		intersection_cubet(t_rt *r, t_obj *ct)
{
	t_vecteur		x;
	long double		c[5];

	x = sub(r->ray.org, ct->pos);
	c[4] = (r->u.x * r->u.x * r->u.x * r->u.x) +
	(r->u.y * r->u.y * r->u.y * r->u.y) + (r->u.z * r->u.z * r->u.z * r->u.z);
	c[3] = 4 * ((r->u.x * r->u.x * r->u.x) * x.x +
	(r->u.y * r->u.y * r->u.y) * x.y + (r->u.z * r->u.z * r->u.z) * x.z);
	c[2] = 6 * ((r->u.x * r->u.x) * (x.x * x.x) +
	(r->u.y * r->u.y) * (x.y * x.y) + (r->u.z * r->u.z) * (x.z * x.z)) - 5 *
	((r->u.x * r->u.x) + (r->u.y * r->u.y) + (r->u.z * r->u.z));
	c[1] = 4 * ((r->u.x * x.x * x.x * x.x) + (r->u.y * x.y * x.y * x.y) +
	(r->u.z * x.z * x.z * x.z)) - 10 * (r->u.x * x.x + r->u.y * x.y +
	r->u.z * x.z);
	c[0] = (x.x * x.x * x.x * x.x) + (x.y * x.y * x.y * x.y) +
	(x.z * x.z * x.z * x.z) - 5 * ((x.x * x.x) + (x.y * x.y) + (x.z * x.z)) +
	11.8;
	return (distances2(r, c));
}

int		rat_trace_cubet(t_rt *r, t_obj *obj)
{
	if (intersection_cubet(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}
