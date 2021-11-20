/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normals_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 05:48:32 by mderri            #+#    #+#             */
/*   Updated: 2020/11/12 18:16:54 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			torus_normal(t_rt *r, t_obj *obj)
{
	long double k;
	long double m;
	t_vecteur	a;
	t_vecteur	v;

	a = r->u;
	v = normalise(obj->axe);
	k = dot(sub(obj->inter, obj->pos), v);
	a = sub(obj->inter, kv(v, k));
	m = obj->k * obj->k - k * k;
	m = sqrt(m);
	obj->normal = sub(obj->inter, sub(a, kv(sub(obj->pos, a),
	m / obj->l + m)));
	obj->normal = normalise(obj->normal);
}

void			paraboloid_normal(t_rt *r, t_obj *obj)
{
	long double	m;
	t_vecteur	v;

	v = normalise(obj->axe);
	m = dot(r->u, kv(v, r->dis));
	m += dot(sub(r->ray.org, obj->pos), v);
	obj->normal = sub(sub(obj->inter, obj->pos), kv(obj->axe, m + obj->k));
	obj->normal = normalise(obj->normal);
}

void			ellipsoid_normal(t_rt *r, t_obj *obj)
{
	t_vecteur	p;

	p = r->u;
	p = sub(obj->inter, obj->pos);
	obj->normal.x = 2 * p.x / obj->axe.x * obj->axe.x;
	obj->normal.y = 2 * p.y / obj->axe.y * obj->axe.y;
	obj->normal.z = 2 * p.z / obj->axe.z * obj->axe.z;
	obj->normal = normalise(obj->normal);
}

void			hyperboloid_normal(t_rt *r, t_obj *obj)
{
	t_vecteur		p;

	p = r->u;
	p = sub(obj->inter, obj->pos);
	obj->normal.x = 2 * p.x / obj->axe.x * obj->axe.x;
	obj->normal.y = 2 * p.y / obj->axe.y * obj->axe.y;
	obj->normal.z = -2 * p.z / obj->axe.z * obj->axe.z;
	obj->normal = normalise(obj->normal);
}

void			cubet_normal(t_rt *r, t_obj *obj)
{
	t_vecteur		p;

	p = r->u;
	p = sub(obj->inter, obj->pos);
	obj->normal.x = 4 * p.x * p.x * p.x - 10 * p.x;
	obj->normal.y = 4 * p.y * p.y * p.y - 10 * p.y;
	obj->normal.z = 4 * p.z * p.z * p.z - 10 * p.z;
	obj->normal = normalise(obj->normal);
}
