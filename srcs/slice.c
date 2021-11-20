/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:00:51 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 17:02:26 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		slice_plan(t_obj *obj, t_vecteur p)
{
	if (fabs((double)(long double)p.x) > obj->limitx ||
	fabs((double)(long double)p.z) > obj->limitz)
		return (0);
	return (1);
}

int		slice_cylinder(t_obj *obj, t_vecteur p)
{
	if (fabs((double)(long double)p.y) > obj->limit)
		return (0);
	return (1);
}

int		slice_sphere(t_vecteur p)
{
	if (p.y < 0)
		return (0);
	return (1);
}

int		slice(t_obj *obj, t_vecteur p)
{
	if (obj->type == tplane)
		return (slice_plan(obj, p));
	if (obj->type == tcylinder || obj->type == tcone)
		return (slice_cylinder(obj, p));
	if (obj->type == tsphere)
		return (slice_sphere(p));
	return (1);
}
