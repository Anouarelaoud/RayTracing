/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:31:58 by mderri            #+#    #+#             */
/*   Updated: 2020/03/19 07:25:43 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		intersection_t(t_rt *r, t_obj *t)
{
	t_coef		co;
	long double	c[5];
	t_vecteur	x;

	x = sub(r->ray.org, t->pos);
	co.m = dot(r->u, r->u);
	co.n = dot(r->u, x);
	co.o = dot(x, x);
	co.p = dot(r->u, t->axe);
	co.q = dot(x, t->axe);
	c[4] = co.m * co.m;
	c[3] = 4 * co.m * co.n;
	c[2] = 4 * co.n * co.n + 2 * co.m * co.o - 2 * co.m * (t->l * t->l +
	t->k * t->k) + 4 * t->l * t->l * co.p * co.p;
	c[1] = 4 * co.n * co.o - 4 * co.n * (t->l * t->l + t->k * t->k) +
	8 * t->l * t->l * co.p * co.q;
	c[0] = co.o * co.o - 2 * co.o * (t->l * t->l + t->k * t->k) +
	4 * t->l * t->l * co.q * co.q + pow((t->l * t->l - t->k * t->k), 2);
	return (distances2(r, c));
}

int		rat_trace_torus(t_rt *r, t_obj *obj)
{
	if (intersection_t(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}
