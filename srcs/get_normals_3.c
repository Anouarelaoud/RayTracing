/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normals_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 05:48:42 by mderri            #+#    #+#             */
/*   Updated: 2020/11/12 18:17:55 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			plane_normal(t_obj *obj)
{
	obj->normal = normalise(obj->axe);
}

void			moebius_normal(t_rt *r, t_obj *obj)
{
	t_vecteur		p;

	p = r->u;
	p = sub(obj->inter, obj->pos);
	obj->normal.x = 2 * p.x * p.y - 4 * p.x * p.z - 2 * p.z * obj->k;
	obj->normal.y = 3 * p.y * p.y - 4 * p.y * p.z + p.x * p.x + p.z * p.z -
	obj->k * obj->k;
	obj->normal.z = -2 * p.y * p.y + 2 * p.y * p.z - 4 * p.x * p.z - 2 * p.x *
	obj->k;
	obj->normal = normalise(obj->normal);
}

void			dingdong_normal(t_rt *r, t_obj *obj)
{
	t_vecteur		p;

	p = r->u;
	p = sub(obj->inter, obj->pos);
	obj->normal.x = 2 * p.x;
	obj->normal.y = 2 * p.y;
	obj->normal.z = 3 * p.z * p.z - 2 * p.z;
	obj->normal = normalise(obj->normal);
}

void			goursat_normal(t_rt *r, t_obj *obj)
{
	t_vecteur		p;

	p = r->u;
	p = sub(obj->inter, obj->pos);
	obj->normal.x = 4 * p.x * p.x * p.x;
	obj->normal.y = 4 * p.y * p.y * p.y;
	obj->normal.z = 4 * p.z * p.z * p.z;
	obj->normal = normalise(obj->normal);
}

void			teardrop_normal(t_rt *r, t_obj *obj)
{
	t_vecteur		p;

	p = r->u;
	p = sub(obj->inter, obj->pos);
	obj->normal.x = 2 * p.x;
	obj->normal.y = 2 * p.y;
	obj->normal.z = 4 * p.z * p.z * p.z - 3 * p.z * p.z;
	obj->normal = normalise(obj->normal);
}
