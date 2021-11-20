/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tear_drop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 06:24:22 by mderri            #+#    #+#             */
/*   Updated: 2020/11/12 06:24:25 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int					intersection_teardrop(t_rt *r, t_obj *td)
{
	t_vecteur		x;
	long double		c[5];

	x = sub(r->ray.org, td->pos);
	c[4] = (r->u.z * r->u.z * r->u.z * r->u.z);
	c[3] = (r->u.z * r->u.z * r->u.z) * (4 * x.z - 1);
	c[2] = 6 * (r->u.z * r->u.z) * (x.z * x.z) -
	3 * (r->u.z * r->u.z) * x.z + (r->u.x * r->u.x) + (r->u.y * r->u.y);
	c[1] = (4 * r->u.z * x.z * x.z * x.z) - (3 * r->u.z * x.z * x.z) +
	2 * (r->u.x * x.x + r->u.y * x.y);
	c[0] = (x.z * x.z * x.z) * (x.z - 1) + (x.x * x.x) + (x.y + x.y);
	return (distances2(r, c));
}

int					rat_trace_teardrop(t_rt *r, t_obj *obj)
{
	if (intersection_teardrop(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}
