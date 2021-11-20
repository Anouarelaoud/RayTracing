/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:56:37 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 01:26:03 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			shadow_goursat(t_rt *r, t_obj *obj)
{
	if (intersection_goursat(r, obj))
		return (1);
	return (0);
}

int			shadow_teardrop(t_rt *r, t_obj *obj)
{
	if (intersection_teardrop(r, obj))
		return (1);
	return (0);
}

int			cast_shadow2(t_rt *r, t_obj *compos)
{
	if ((compos->type == tsphere) && shadow_s(r, compos))
		return (1);
	if (((compos->type == tplane) || (compos->type == tdisk)) &&
shadow_p(r, compos))
		return (1);
	if ((compos->type == tcone) && shadow_co(r, compos))
		return (1);
	if ((compos->type == tcylinder) && shadow_c(r, compos))
		return (1);
	if ((compos->type == ttorus) && shadow_t(r, compos))
		return (1);
	if ((compos->type == tparaboloid) && shadow_pb(r, compos))
		return (1);
	if ((compos->type == tellipsoid) && shadow_ell(r, compos))
		return (1);
	if ((compos->type == thyperboloid) && shadow_hp(r, compos))
		return (1);
	if ((compos->type == tcubet) && shadow_cubet(r, compos))
		return (1);
	if ((compos->type == tmoebius) && shadow_moebius(r, compos))
		return (1);
	if ((compos->type == tdingdong) && shadow_dingdong(r, compos))
		return (1);
	return (0);
}

int			cast_shadow3(t_rt *r, t_obj *compos)
{
	if (cast_shadow2(r, compos))
		return (1);
	if ((compos->type == tgoursat) && shadow_goursat(r, compos))
		return (1);
	if ((compos->type == tteardrop) && shadow_teardrop(r, compos))
		return (1);
	return (0);
}

int			cast_shadow(t_rt *r)
{
	t_obj		*obj_list;
	t_obj		*compos;

	obj_list = r->head;
	while (obj_list)
	{
		compos = obj_list->head_compos;
		while (compos)
		{
			if (compos == r->obj)
			{
				if (compos->next)
					compos = compos->next;
				else
					break ;
			}
			if (cast_shadow3(r, compos))
				return (1);
			compos = compos->next;
		}
		obj_list = obj_list->next;
	}
	return (0);
}
