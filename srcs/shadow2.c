/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:24:45 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 18:25:20 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				shadow_s(t_rt *r, t_obj *obj)
{
	if (intersection_s(r, obj))
		return (1);
	return (0);
}

int				shadow_p(t_rt *r, t_obj *obj)
{
	if (obj->type == tplane && intersection_p(r, obj))
		return (1);
	if (obj->type == tdisk && disk_intersection(r, obj))
		return (1);
	return (0);
}

int				shadow_co(t_rt *r, t_obj *obj)
{
	if (intersection_co(r, obj))
		return (1);
	return (0);
}

int				shadow_c(t_rt *r, t_obj *obj)
{
	if (intersection_c(r, obj))
		return (1);
	return (0);
}

int				shadow_t(t_rt *r, t_obj *obj)
{
	if (intersection_t(r, obj))
		return (1);
	return (0);
}
