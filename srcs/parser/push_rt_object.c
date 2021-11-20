/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rt_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 06:43:52 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/12 20:31:35 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	check_obj_props(t_rt *rt, int type)
{
	if (type == tplane)
		check_plane_props(rt);
	else if (type == tsphere)
		check_sphere_props(rt);
	else if (type == tcylinder)
		check_cylinder_props(rt);
	else if (type == tcone)
		check_cone_props(rt);
	else if (type == ttorus)
		check_torus_props(rt);
	else if (type == tparaboloid)
		check_paraboloid_props(rt);
	else if (type == tellipsoid)
		check_ellipsoid_props(rt);
	else if (type == thyperboloid)
		check_ellipsoid_props(rt);
	else if (type == tcubet || type == tdingdong ||
type == tgoursat || type == tteardrop)
		check_cubet_props(rt);
	else if (type == tmoebius)
		check_moebius_props(rt);
	else if (type == tcube)
		check_cube_props(rt);
}

static void	get_obj(t_rt *rt, int type, t_obj **obj)
{
	if (type == tplane)
		get_plane(rt, obj);
	else if (type == tsphere)
		get_sphere(rt, obj);
	else if (type == tcylinder)
		get_cylinder(rt, obj);
	else if (type == tcone)
		get_cone(rt, obj);
	else if (type == ttorus)
		get_torus(rt, obj);
	else if (type == tparaboloid)
		get_paraboloid(rt, obj);
	else if (type == tellipsoid)
		get_ellipsoid(rt, obj);
	else if (type == thyperboloid)
		get_ellipsoid(rt, obj);
	else if (type == tcubet || type == tdingdong ||
type == tgoursat || type == tteardrop)
		get_cubet(rt, obj);
	else if (type == tmoebius)
		get_moebius(rt, obj);
	else if (type == tcube)
		get_cube(rt, obj);
}

void		project_obj(t_obj **obj, int type)
{
	t_vecteur rec;

	rec = create_v((*obj)->pos.x, (*obj)->pos.y, (*obj)->pos.z);
	(*obj)->pos = create_v(0.0, 0.0, 0.0);
	(*obj)->axe = normalise((*obj)->axe);
	(*obj)->type = type;
	(*obj)->rot = create_v(deg_to_rad((*obj)->rot.x), deg_to_rad((*obj)->rot.y),
deg_to_rad((*obj)->rot.z));
	(*obj)->repere = set_repere((*obj)->axe);
	project(&((*obj)->repere.i), (*obj)->rot);
	project(&((*obj)->repere.j), (*obj)->rot);
	project(&((*obj)->repere.k), (*obj)->rot);
	project(&((*obj)->axe), (*obj)->rot);
	(*obj)->pos = create_v(rec.x, rec.y, rec.z);
}

static void	init_obj(t_obj **obj)
{
	(*obj)->rot = (t_vecteur){0, 0, 0};
	(*obj)->tr = (t_vecteur){0, 0, 0};
	(*obj)->axe = create_v(0, -1, 0);
	(*obj)->sliced = 0;
	(*obj)->limit = -1;
	(*obj)->limitx = -1;
	(*obj)->limitz = -1;
	(*obj)->parent = NULL;
	(*obj)->noise = n_none;
}

void		push_rt_object(t_rt *rt, int type)
{
	t_obj *obj;

	check_obj_props(rt, type);
	if (!rt->last_obj)
	{
		rt->obj_list = (t_obj *)ft_memalloc(sizeof(t_obj));
		if (!rt->obj_list)
			free_garbage(rt);
		garbage_collector(rt, rt->obj_list);
		obj = rt->obj_list;
	}
	else
	{
		rt->last_obj->next = (t_obj *)ft_memalloc(sizeof(t_obj));
		if (!rt->last_obj->next)
			free_garbage(rt);
		garbage_collector(rt, rt->last_obj->next);
		obj = rt->last_obj->next;
	}
	init_obj(&obj);
	get_obj(rt, type, &obj);
	project_obj(&obj, type);
	add_compos(rt, obj);
	obj->next = NULL;
	rt->last_obj = obj;
}
