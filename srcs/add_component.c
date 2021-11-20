/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_component.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:29:42 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/12 22:49:04 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	duplicate(t_rt *rt, t_obj *obj)
{
	if (!(obj->compos = (t_obj *)malloc(sizeof(t_obj))))
		free_garbage(rt);
	garbage_collector(rt, obj->compos);
	obj->compos->parent = obj;
	obj->head_compos = obj->compos;
	obj->compos->type = obj->type;
	obj->compos->color = obj->color;
	obj->compos->pos = obj->pos;
	obj->compos->axe = obj->axe;
	if (obj->type != tplane)
		obj->compos->k = obj->k;
	obj->compos->l = obj->l;
	obj->compos->noise = obj->noise;
	obj->compos->repere = obj->repere;
	obj->compos->limit = obj->limit;
	if (obj->color.type == c_texture || obj->noise == n_damier)
		obj->compos->txt = obj->txt;
	obj->compos->color.type = obj->color.type;
	obj->compos->t2 = obj->t2;
	obj->compos->sliced = obj->sliced;
	if (obj->type == tplane)
	{
		obj->compos->limitx = obj->limitx;
		obj->compos->limitz = obj->limitz;
	}
}

void	add_plane_compos(t_rt *rt, t_obj *obj)
{
	duplicate(rt, obj);
	obj->compos->next = NULL;
}

void	add_cylinder_compos(t_rt *rt, t_obj *obj)
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
		dup_compos(obj, obj->compos->next, 1.0, obj->k);
		obj->compos->next->next = (struct s_obj *)malloc(sizeof(struct s_obj));
		if (!obj->compos->next->next)
			free_garbage(rt);
		garbage_collector(rt, obj->compos->next->next);
		dup_compos(obj, obj->compos->next->next, -1.0, obj->k);
		obj->compos->next->next->next = NULL;
	}
}
