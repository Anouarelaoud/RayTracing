/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:42:46 by mderri            #+#    #+#             */
/*   Updated: 2020/11/12 22:57:17 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				intersection_s(t_rt *r, t_obj *s)
{
	t_vecteur	param;

	param.x = 1;
	param.y = 2 * dot(r->u, sub(r->ray.org, s->pos));
	param.z = module(sub(r->ray.org, s->pos)) * module(sub(r->ray.org,
	s->pos)) - s->k * s->k;
	r->delta = param.y * param.y - 4 * param.x * param.z;
	if (r->delta < 0)
		return (0);
	r->sol1 = (-param.y - sqrt(r->delta)) / (2 * param.x);
	r->sol2 = (-param.y + sqrt(r->delta)) / (2 * param.x);
	return (distances_tex(r, s));
}

int				rat_trace_sphere(t_rt *r, t_obj *obj)
{
	if (intersection_s(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}

int				getanglesphere(t_obj *sphere_temp, t_vecteur p)
{
	long double phi;
	long double theta;

	phi = atan2(p.z, p.x);
	theta = asin(p.y / sphere_temp->k);
	sphere_temp->txt->um = fmod(1 - (phi + M_PI) / (2.0 * M_PI),
	1.0 / sphere_temp->txt->hi) + sphere_temp->txt->x_offset;
	sphere_temp->txt->vm = 1.0 - fmod((theta + M_PI / 2.0) / M_PI,
	1.0 / sphere_temp->txt->hi) + sphere_temp->txt->y_offset;
	return (1);
}
