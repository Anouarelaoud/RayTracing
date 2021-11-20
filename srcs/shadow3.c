/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:24:53 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 18:25:47 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				shadow_pb(t_rt *r, t_obj *obj)
{
	if (intersection_pb(r, obj))
		return (1);
	return (0);
}

int				shadow_ell(t_rt *r, t_obj *obj)
{
	if (intersection_ell(r, obj))
		return (1);
	return (0);
}

int				shadow_hp(t_rt *r, t_obj *obj)
{
	if (intersection_hp(r, obj))
		return (1);
	return (0);
}

int				shadow_cubet(t_rt *r, t_obj *obj)
{
	if (intersection_cubet(r, obj))
		return (1);
	return (0);
}

int				shadow_moebius(t_rt *r, t_obj *obj)
{
	if (intersection_moebius(r, obj))
		return (1);
	return (0);
}
