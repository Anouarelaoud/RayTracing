/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:15:38 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/13 00:08:30 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			final_color(t_rt *r)
{
	r->color.r += r->diff.r + r->spec.r;
	r->color.g += r->diff.g + r->spec.g;
	r->color.b += r->diff.b + r->spec.b;
}

void			lighting2(t_rt *r, t_light_lst *lst, t_vecteur dir, t_color new)
{
	long double	d;
	long double i;

	r->ray.org = r->obj->inter;
	r->ray.direct = sub(lst->org, r->obj->inter);
	r->dis = module(r->ray.direct);
	i = dot(normalise(lst->axis), normalise(r->ray.direct));
	r->u = normalise(r->ray.direct);
	d = fmax(dot(r->obj->normal, r->u), 0.0);
	i = rad_to_deg(acos(i));
	if (i > lst->angle)
	{
		r->color.r = r->color.r;
		r->color.g = r->color.g;
		r->color.b = r->color.b;
		lst = lst->next;
	}
	else if (!cast_shadow(r))
	{
		diffuse(r, d, lst, new);
		specular(r, d, dir, lst);
		final_color(r);
	}
}
