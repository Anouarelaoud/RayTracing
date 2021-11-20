/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dingdong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 06:08:38 by mderri            #+#    #+#             */
/*   Updated: 2020/11/13 01:26:22 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				intersection_dingdong(t_rt *r, t_obj *d)
{
	t_vecteur	x;
	long double	c[4];

	x = sub(r->ray.org, d->pos);
	c[3] = (r->u.z * r->u.z * r->u.z);
	c[2] = (r->u.x * r->u.x) + (r->u.y * r->u.y) + (3 * r->u.z * r->u.z * x.z) -
	(r->u.z * r->u.z);
	c[1] = 2 * (r->u.x * x.x + r->u.y * x.y - r->u.z * x.z) +
	3 * (r->u.z * x.z * x.z);
	c[0] = (x.x * x.x) + (x.y * x.y) - (x.z * x.z) + (x.z * x.z * x.z);
	return (distances3(r, c));
}

int				rat_trace_dingdong(t_rt *r, t_obj *obj)
{
	if (intersection_dingdong(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}

int				distances(t_rt *r)
{
	if (((r->sol2 < r->sol1 || r->sol1 < MIN) && r->sol2 > MIN)
			&& (r->sol2 < r->dis))
	{
		r->dis = r->sol2;
		return (1);
	}
	else if (((r->sol1 < r->sol2 || r->sol2 < MIN) && r->sol1 > MIN)
			&& (r->sol1 < r->dis))
	{
		r->dis = r->sol1;
		return (1);
	}
	else
		return (0);
}

int				shadow_dingdong(t_rt *r, t_obj *obj)
{
	if (intersection_dingdong(r, obj))
		return (1);
	return (0);
}
