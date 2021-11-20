/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise_change_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 04:09:59 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 05:08:10 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	perlin_noise_event(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.noise_perlin->x && x < (rt->ui.noise_perlin->x +
rt->ui.noise_perlin->w)) && (y > rt->ui.noise_perlin->y &&
y < (rt->ui.noise_perlin->y + rt->ui.noise_perlin->h)))
	{
		rt->last_obj->next = (t_obj *)ft_memalloc(sizeof(t_obj));
		if (!rt->last_obj->next)
			free_garbage(rt);
		garbage_collector(rt, rt->last_obj->next);
		if (rt->selected->noise != n_perlin)
		{
			apply_noise(rt, n_perlin);
			raytracer(rt);
		}
	}
}

static void	voronoi_noise_event(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.noise_voronoi->x && x < (rt->ui.noise_voronoi->x +
rt->ui.noise_voronoi->w)) && (y > rt->ui.noise_voronoi->y &&
y < (rt->ui.noise_voronoi->y + rt->ui.noise_voronoi->h)))
	{
		rt->last_obj->next = (t_obj *)ft_memalloc(sizeof(t_obj));
		if (!rt->last_obj->next)
			free_garbage(rt);
		garbage_collector(rt, rt->last_obj->next);
		if (rt->selected->noise != n_voronoi)
		{
			apply_noise(rt, n_voronoi);
			raytracer(rt);
		}
	}
}

static void	damier_noise_event(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.noise_damier->x && x < (rt->ui.noise_damier->x +
rt->ui.noise_damier->w)) && (y > rt->ui.noise_damier->y &&
y < (rt->ui.noise_damier->y + rt->ui.noise_damier->h)))
	{
		rt->last_obj->next = (t_obj *)ft_memalloc(sizeof(t_obj));
		if (!rt->last_obj->next)
			free_garbage(rt);
		garbage_collector(rt, rt->last_obj->next);
		if (rt->selected->noise != n_damier)
		{
			apply_noise(rt, n_damier);
			raytracer(rt);
		}
	}
}

static void	no_noise_event(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.none->x && x < (rt->ui.none->x +
rt->ui.none->w)) && (y > rt->ui.none->y &&
y < (rt->ui.none->y + rt->ui.none->h)))
	{
		rt->last_obj->next = (t_obj *)ft_memalloc(sizeof(t_obj));
		if (!rt->last_obj->next)
			free_garbage(rt);
		garbage_collector(rt, rt->last_obj->next);
		if (rt->selected->noise != n_none)
		{
			apply_noise(rt, n_none);
			raytracer(rt);
		}
	}
}

void		noise_change_event(t_rt *r, int x, int y)
{
	if (r->selected->color.type != c_texture)
	{
		perlin_noise_event(r, x, y);
		voronoi_noise_event(r, x, y);
		damier_noise_event(r, x, y);
		no_noise_event(r, x, y);
	}
}
