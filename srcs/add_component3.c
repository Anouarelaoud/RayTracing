/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_component3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:31:05 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/13 00:31:06 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	dup_cube(t_rt *rt, t_obj *obj, t_obj **compos, int cas)
{
	if (!(*compos = (struct s_obj *)malloc(sizeof(struct s_obj))))
		free_garbage(rt);
	garbage_collector(rt, *compos);
	(*compos)->parent = obj;
	(*compos)->sliced = 1;
	(*compos)->type = tplane;
	(*compos)->color = obj->color;
	(*compos)->color.type = obj->color.type;
	(*compos)->limitx = obj->k;
	(*compos)->limitz = obj->k;
	(*compos)->t2 = obj->t2;
	(*compos)->repere = obj->repere;
	if (cas == 1)
	{
		obj->head_compos = *compos;
		(*compos)->pos = sum(obj->pos, kv(obj->repere.j, 1.0 * obj->k));
		(*compos)->axe = obj->repere.j;
	}
	else if (cas == 2)
	{
		(*compos)->pos = sum(obj->pos, kv(obj->repere.j, -1.0 * obj->k));
		(*compos)->axe = kv(obj->repere.j, -1.0);
	}
}

static void	dup_cube2(t_rt *rt, t_obj *obj, t_obj **compos, int cas)
{
	if (!(*compos = (struct s_obj *)malloc(sizeof(struct s_obj))))
		free_garbage(rt);
	garbage_collector(rt, *compos);
	(*compos)->parent = obj;
	(*compos)->sliced = 1;
	(*compos)->type = tplane;
	(*compos)->color = obj->color;
	(*compos)->color.type = obj->color.type;
	(*compos)->limitx = obj->k;
	(*compos)->limitz = obj->k;
	(*compos)->t2 = obj->t2;
	(*compos)->repere.i = obj->repere.j;
	(*compos)->repere.k = obj->repere.k;
	(*compos)->repere.j = obj->repere.i;
	if (cas == 3)
	{
		(*compos)->pos = sum(obj->pos, kv(obj->repere.i, 1.0 * obj->k));
		(*compos)->axe = kv(obj->repere.i, -1.0);
	}
	else if (cas == 4)
	{
		(*compos)->pos = sum(obj->pos, kv(obj->repere.i, -1.0 * obj->k));
		(*compos)->axe = kv(obj->repere.i, -1.0);
	}
}

static void	dup_cube3(t_rt *rt, t_obj *obj, t_obj **compos, int cas)
{
	if (!(*compos = (struct s_obj *)malloc(sizeof(struct s_obj))))
		free_garbage(rt);
	garbage_collector(rt, *compos);
	(*compos)->parent = obj;
	(*compos)->sliced = 1;
	(*compos)->type = tplane;
	(*compos)->color = obj->color;
	(*compos)->color.type = obj->color.type;
	(*compos)->limitx = obj->k;
	(*compos)->limitz = obj->k;
	(*compos)->t2 = obj->t2;
	(*compos)->repere.i = obj->repere.i;
	(*compos)->repere.j = obj->repere.k;
	(*compos)->repere.k = obj->repere.j;
	if (cas == 5)
	{
		(*compos)->pos = sum(obj->pos, kv(obj->repere.k, 1.0 * obj->k));
		(*compos)->axe = obj->repere.k;
	}
	else if (cas == 6)
	{
		(*compos)->pos = sum(obj->pos, kv(obj->repere.k, -1.0 * obj->k));
		(*compos)->axe = kv(obj->repere.k, -1.0);
	}
}

void		add_cube_compos(t_rt *rt, t_obj *obj)
{
	dup_cube(rt, obj, &(obj->compos), 1);
	dup_cube(rt, obj, &(obj->compos->next), 2);
	dup_cube2(rt, obj, &(obj->compos->next->next), 3);
	dup_cube2(rt, obj, &(obj->compos->next->next->next), 4);
	dup_cube3(rt, obj, &(obj->compos->next->next->next->next), 5);
	dup_cube3(rt, obj, &(obj->compos->next->next->next->next->next), 6);
	obj->compos->next->next->next->next->next->next = NULL;
}
