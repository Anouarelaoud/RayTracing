/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:02:59 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 22:55:20 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			getangle(t_obj *obj, t_vecteur inter)
{
	if (obj->type == tsphere)
		return (getanglesphere(obj, inter));
	else if (obj->type == tplane)
		return (getangleplan(obj, inter));
	else if (obj->type == tcylinder)
		return (getanglecylinder(obj, inter));
	else if (obj->type == tcone)
		return (getanglecone(obj, inter));
	return (0);
}

int			getcolorfromtexture(t_rt *rt, t_obj *obj, long double t)
{
	int			i[3];
	t_vecteur	inter;
	t_vecteur	p;

	inter = sub(obj->pos, sum(kv(rt->u, t), rt->ray.org));
	p = create_v(dot(inter, obj->repere.i), dot(inter, obj->repere.j),
	dot(inter, obj->repere.k));
	if (obj->sliced == 1)
		return (slice(obj, p));
	if (obj->color.type == c_texture)
	{
		i[2] = getangle(obj, p);
		i[0] = obj->txt->um * obj->txt->w;
		i[1] = (1.0 - obj->txt->vm) * obj->txt->h - 0.001;
		i[0] = (i[0] < 0) ? 0 : i[0];
		i[1] = (i[1] < 0) ? 0 : i[1];
		i[0] = (i[0] > obj->txt->w - 1) ? obj->txt->w - 1 : i[0];
		i[1] = (i[1] > obj->txt->h - 1) ? obj->txt->h - 1 : i[1];
		if (obj->txt->buf[i[1] * obj->txt->w + i[0]] == -16777216 || i[2] == 0)
			return (0);
		obj->color.r = (obj->txt->buf[i[1] * obj->txt->w + i[0]] >> 16) & 0xFF;
		obj->color.g = (obj->txt->buf[i[1] * obj->txt->w + i[0]] >> 8) & 0xFF;
		obj->color.b = obj->txt->buf[i[1] * obj->txt->w + i[0]] & 0xFF;
	}
	return (1);
}

void		texture(t_rt *rt)
{
	t_obj	*obj;
	t_obj	*compos;

	obj = rt->head;
	while (obj)
	{
		compos = obj->head_compos;
		while (compos)
		{
			if (compos->color.type == c_texture)
			{
				if (!(load_texture(rt, compos, compos->txt->path)))
					xml_error(rt, "Cannot open texture.");
			}
			compos = compos->next;
		}
		obj = obj->next;
	}
}
