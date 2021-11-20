/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moebius.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:47:05 by mderri            #+#    #+#             */
/*   Updated: 2020/03/19 07:26:46 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				intersection_moebius(t_rt *r, t_obj *m)
{
	long double	c[4];
	long double	h[7];

	h[0] = r->ray.org.x;
	h[1] = r->ray.org.y;
	h[2] = r->ray.org.z;
	h[3] = r->u.x;
	h[4] = r->u.y;
	h[5] = r->u.z;
	h[6] = (int)m->k;
	c[0] = h[1] * h[1] * h[1] - 2 * h[1] * h[1] * h[2] + h[0] * h[0] * h[1]
		+ h[1] * h[2] * h[2] - h[1] * h[6] * h[6] - 2 * h[0] * h[0] * h[2]
		- 2 * h[0] * h[2] * h[6];
	c[1] = 3 * h[4] * h[1] * h[1] - 4 * h[4] * h[1] * h[2] - 2 * h[5] * h[1]
		* h[1] + 2 * h[3] * h[0] * h[1] + 2 * h[5] * h[1] * h[2] + h[4]
		* h[0] * h[0] + h[4] * h[2] * h[2] - h[4] * h[6] * h[6]
		- 4 * h[3] * h[0] * h[2] - 2 * h[5] * h[0] * h[0]
		- 2 * h[5] * h[0] * h[6] - 2 * h[3] * h[2] * h[6];
	c[2] = 3 * h[4] * h[4] * h[1] - 2 * h[4] * h[4] * h[2] + h[3] * h[3] *
h[1] + h[5] * h[5] * h[1] + 2 * h[3] * h[4] * h[0] + 2 * h[4] * h[5] * h[2] -
4 * h[3] * h[5] * h[0] - 2 * h[3] * h[5] * h[6] - 2 * h[3] * h[3] * h[2] - 4 *
h[4] * h[5] * h[1];
	c[3] = h[4] * h[4] * h[4] + h[3] * h[3] * h[4] + h[4] * h[5] * h[5]
		- 2 * h[3] * h[3] * h[5] - 2 * h[4] * h[4] * h[5];
	return (distances4(r, c, m));
}

int				in_moebius(t_obj *m, t_vecteur p)
{
	t_vecteur	param;
	long double	v;
	long double	u;
	long double	km;

	km = 3 * m->k / 4;
	v = atan2(p.y, p.x);
	u = km;
	if (sin(v / 2) != 0.0)
		u = p.z / sin(v / 2);
	else if (cos(v) != 0.0 && cos(v / 2) != 0.0)
		u = (p.x / cos(v) - m->k) / cos(v / 2);
	else if (sin(v) != 0.0 && cos(v / 2) != 0.0)
		u = (p.y / sin(v) - m->k) / cos(v / 2);
	if (!(u >= -km && u <= km))
		return (0);
	param.x = (m->k + u * cos(v / 2)) * cos(v);
	param.y = (m->k + u * cos(v / 2)) * sin(v);
	param.z = u * sin(v / 2);
	param = sub(p, param);
	v = module(param);
	if (v > 0.000001 || v < -0.000001)
		return (0);
	return (1);
}

int				rat_trace_moebius(t_rt *r, t_obj *obj)
{
	if (intersection_moebius(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}
