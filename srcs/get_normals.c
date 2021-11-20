/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 02:35:11 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/12 23:31:38 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			cone_normal(t_rt *r, t_obj *obj)
{
	t_vecteur	assist;
	long double	m;
	t_vecteur	v;

	v = normalise(obj->axe);
	m = dot(r->u, kv(v, r->dis));
	m += dot(sub(r->ray.org, obj->pos), v);
	assist = sub(obj->inter, obj->pos);
	obj->normal = sub(assist, kv(v, (1 + obj->k * obj->k) * m));
	obj->normal = normalise(obj->normal);
}

void			sphere_normal(t_obj *obj)
{
	obj->normal = sub(obj->inter, obj->pos);
	obj->normal = normalise(obj->normal);
}

void			cylinder_normal(t_rt *r, t_obj *obj)
{
	t_vecteur	assist;
	long double	m;
	t_vecteur	v;

	v = normalise(obj->axe);
	m = dot(r->u, kv(v, r->dis));
	m += dot(sub(r->ray.org, obj->pos), v);
	assist = sub(obj->inter, obj->pos);
	obj->normal = sub(assist, kv(v, m));
	obj->normal = normalise(obj->normal);
}

void			get_normal1(t_rt *r, t_obj *obj)
{
	if (obj->type == tplane || obj->type == tdisk)
		plane_normal(obj);
	if (obj->type == tsphere)
		sphere_normal(obj);
	if (obj->type == tcylinder)
		cylinder_normal(r, obj);
	if (obj->type == tcone)
		cone_normal(r, obj);
	if (obj->type == ttorus)
		torus_normal(r, obj);
	if (obj->type == tparaboloid)
		paraboloid_normal(r, obj);
	if (obj->type == tellipsoid)
		ellipsoid_normal(r, obj);
	if (obj->type == thyperboloid)
		hyperboloid_normal(r, obj);
	if (obj->type == tcubet)
		cubet_normal(r, obj);
	if (obj->type == tmoebius)
		moebius_normal(r, obj);
	if (obj->type == tdingdong)
		dingdong_normal(r, obj);
	if (obj->type == tgoursat)
		goursat_normal(r, obj);
}

void			get_normal(t_rt *r, t_obj *obj)
{
	get_normal1(r, obj);
	if (obj->type == tteardrop)
		teardrop_normal(r, obj);
}
