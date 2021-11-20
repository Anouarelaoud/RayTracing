/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:32:13 by mderri            #+#    #+#             */
/*   Updated: 2020/11/13 01:33:34 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

long double		racine_cubique(long double n)
{
	long double pow1;
	long double pow2;
	long double rc;

	pow1 = pow((long double)(n), 1.0 / 3.0);
	pow2 = pow((long double)-(n), 1.0 / 3.0);
	if (n > 0.0)
		rc = pow1;
	else
	{
		if (n < 0.0)
			rc = -pow2;
		else
			rc = 0.0;
	}
	return (rc);
}

int				is_zero(long double delta)
{
	return ((delta > -EQN_EPS && delta < EQN_EPS));
}

int				ft_solve_quadric(long double w[3], long double s[2])
{
	long double	p;
	long double	q;
	long double	d;

	p = w[1] / (2.0 * w[2]);
	q = w[0] / w[2];
	d = p * p - q;
	if (is_zero(d))
	{
		s[0] = -p;
		return (1);
	}
	else if (d < 0)
		return (0);
	else
	{
		d = sqrt(d);
		s[0] = d - p;
		s[1] = -d - p;
		return (2);
	}
}

void			cast_object_help(t_rt *r, t_obj *compos)
{
	if (compos->type == ttorus)
		rat_trace_torus(r, compos);
	else if (compos->type == tparaboloid)
		rat_trace_paraboloid(r, compos);
	else if (compos->type == tellipsoid)
		rat_trace_ellipsoid(r, compos);
	else if (compos->type == thyperboloid)
		rat_trace_hyperboloid(r, compos);
	else if (compos->type == tcubet)
		rat_trace_cubet(r, compos);
	else if (compos->type == tmoebius)
		rat_trace_moebius(r, compos);
	else if (compos->type == tdingdong)
		rat_trace_dingdong(r, compos);
	else if (compos->type == tgoursat)
		rat_trace_goursat(r, compos);
	else if (compos->type == tteardrop)
		rat_trace_teardrop(r, compos);
	else if (compos->type == tdisk)
		rat_trace_disk(r, compos);
	else if (compos->type == tcone)
		rat_trace_cone(r, compos);
}
