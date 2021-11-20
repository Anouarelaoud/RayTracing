/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:43:43 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 23:21:13 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		disk_intersection(t_rt *rt, t_obj *plane)
{
	t_vecteur	vect;
	long double	a;
	long double	b;
	long double sol;

	vect = sub(rt->ray.org, plane->pos);
	a = -dot(vect, plane->axe);
	b = dot(rt->u, plane->axe);
	sol = a / b;
	vect = sum(rt->ray.org, kv(rt->u, sol));
	if (module(sub(vect, plane->pos)) > plane->k)
		return (0);
	if (sol >= MIN && sol < rt->dis)
	{
		rt->dis = sol;
		return (1);
	}
	return (0);
}

int		rat_trace_disk(t_rt *r, t_obj *obj)
{
	if (disk_intersection(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}
