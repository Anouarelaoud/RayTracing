/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 03:43:43 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 00:12:44 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			ambient(t_rt *r, t_color new)
{
	r->diff = (t_color){.r = 0.0, .g = 0.0, .b = 0.0};
	r->spec = (t_color){.r = 0.0, .g = 0.0, .b = 0.0};
	r->color = (t_color){.r = 0.0, .g = 0.0, .b = 0.0};
	r->color.r += r->amb * new.r;
	r->color.g += r->amb * new.g;
	r->color.b += r->amb * new.b;
}

void			diffuse(t_rt *r, long double d, t_light_lst *lst, t_color new)
{
	r->diff.r = d * 0.6 *
(long double)(lst->color.r * lst->intensity / 255) * new.r;
	r->diff.g = d * 0.6 *
(long double)(lst->color.g * lst->intensity / 255) * new.g;
	r->diff.b = d * 0.6 *
(long double)(lst->color.b * lst->intensity / 255) * new.b;
}

void			specular(t_rt *r, long double d, t_vecteur dir, t_light_lst *l)
{
	t_vecteur	v1;
	t_vecteur	v2;
	long double	tmp;

	if (d == 0)
		tmp = 0;
	else
	{
		v1 = kv(dir, -1.0);
		v2 = sub(kv(r->obj->normal, 2.0 * d), r->u);
		tmp = pow(fmax(dot(v2, v1), 0.0), SPECULAR_POWER);
	}
	r->spec.r = 0.6 * tmp * l->color.r * l->intensity;
	r->spec.g = 0.6 * tmp * l->color.g * l->intensity;
	r->spec.b = 0.6 * tmp * l->color.b * l->intensity;
}

static void		help(t_rt *r, long double *d, t_light_lst *lst)
{
	r->ray.org = r->obj->inter;
	r->ray.direct = sub(lst->org, r->obj->inter);
	r->dis = module(r->ray.direct);
	r->u = normalise(r->ray.direct);
	if (r->obj->type == tplane && dot(r->obj->normal, r->u) < 0.0)
		r->obj->normal = kv(r->obj->normal, -1.0);
	*d = fmax(dot(r->obj->normal, r->u), 0.0);
}

void			lighting(t_rt *r)
{
	t_vecteur	dir;
	long double	d;
	t_light_lst	*lst;
	t_color		new;

	new = get_color(r);
	lst = r->light;
	dir = r->ray.direct;
	ambient(r, new);
	while (lst)
	{
		if (lst->type == lt_flashlight)
			lighting2(r, lst, dir, new);
		else
		{
			help(r, &d, lst);
			if (!cast_shadow(r))
			{
				diffuse(r, d, lst, new);
				specular(r, d, dir, lst);
				final_color(r);
			}
		}
		lst = lst->next;
	}
}
