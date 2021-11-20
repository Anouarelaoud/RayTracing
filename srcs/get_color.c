/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:31:41 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/13 00:31:44 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			get_color(t_rt *rt)
{
	t_vecteur	inter;
	t_vecteur	p;

	if ((rt->obj->color.type == c_default && rt->obj->noise == n_none)
	|| rt->obj->color.type == c_texture)
		return (rt->obj->color);
	inter = sub(rt->obj->pos, sum(kv(rt->u, rt->dis), rt->ray.org));
	p = create_v(dot(inter, rt->obj->repere.i), dot(inter, rt->obj->repere.j),
	dot(inter, rt->obj->repere.k));
	if (rt->obj->noise == n_voronoi)
		return (voronoi_noise(p));
	if (rt->obj->noise == n_perlin)
		return (perlin(rt, p, rt->obj));
	if (rt->obj->noise == n_damier)
		return (checkerboard(rt->obj, p));
	return (rt->obj->color);
}
