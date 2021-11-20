/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_component2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:31:47 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 20:35:34 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_cone_compos(t_rt *rt, t_obj *obj)
{
	duplicate(rt, obj);
	if (obj->sliced == 0)
		obj->compos->next = NULL;
	else
	{
		obj->compos->next = (struct s_obj *)malloc(sizeof(struct s_obj));
		if (!obj->compos->next)
			free_garbage(rt);
		garbage_collector(rt, obj->compos->next);
		dup_compos(obj, obj->compos->next, 1.0, tan((obj->k)) * obj->limit);
		obj->compos->next->next = (struct s_obj *)malloc(sizeof(struct s_obj));
		if (!obj->compos->next->next)
			free_garbage(rt);
		garbage_collector(rt, obj->compos->next->next);
		dup_compos(obj, obj->compos->next->next, -1.0,
		tan((obj->k)) * obj->limit);
		obj->compos->next->next->next = NULL;
	}
}

void	add_sphere_compos(t_rt *rt, t_obj *obj)
{
	obj->limit = 0.0;
	obj->compos = (struct s_obj *)malloc(sizeof(struct s_obj));
	if (!obj->compos)
		free_garbage(rt);
	garbage_collector(rt, obj->compos);
	duplicate(rt, obj);
	if (obj->sliced == 0)
		obj->compos->next = NULL;
}

void	dup_compos(t_obj *obj, t_obj *compos, long double x, long double r)
{
	compos->parent = obj;
	compos->type = tdisk;
	compos->color = obj->color;
	compos->noise = obj->noise;
	compos->pos = sum(obj->pos, kv(obj->axe, x * obj->limit));
	compos->axe = obj->axe;
	compos->repere = obj->repere;
	compos->k = r;
	compos->color.type = obj->color.type;
	compos->t2 = obj->t2;
}

void	add_compos(t_rt *rt, t_obj *obj)
{
	if (obj->type == tplane)
		add_plane_compos(rt, obj);
	if (obj->type == tcylinder)
		add_cylinder_compos(rt, obj);
	else if (obj->type == tcone)
		add_cone_compos(rt, obj);
	else if (obj->type == tsphere)
		add_sphere_compos(rt, obj);
	else if (obj->type == tcube)
		add_cube_compos(rt, obj);
	else if (obj->type == ttorus || obj->type == tparaboloid ||
	obj->type == tellipsoid || obj->type == thyperboloid ||
	obj->type == tcubet || obj->type == tmoebius ||
	obj->type == tdingdong || obj->type == tgoursat || obj->type == tteardrop)
	{
		duplicate(rt, obj);
		obj->compos->next = NULL;
	}
}
