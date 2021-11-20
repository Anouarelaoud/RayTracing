/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hover1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 03:53:20 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/11 04:57:28 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	hover_voronoi(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.noise_voronoi->x && x < (rt->ui.noise_voronoi->x +
					rt->ui.noise_voronoi->w)) && (y > rt->ui.noise_voronoi->y
					&& y < (rt->ui.noise_voronoi->y + rt->ui.noise_voronoi->h)))
	{
		if (rt->ui.noise_voronoi->hovered == 0)
		{
			rt->ui.noise_voronoi->hovered = 1;
			update_ui_element(rt,
&rt->ui.noise_voronoi, "./assets/interface/noise-voronoi-hovered.png");
		}
	}
	else
	{
		if (rt->ui.noise_voronoi->hovered == 1)
		{
			rt->ui.noise_voronoi->hovered = 0;
			update_ui_element(rt,
&rt->ui.noise_voronoi, "./assets/interface/noise-voronoi-normal.png");
		}
	}
}

static void	hover_perlin(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.noise_perlin->x && x < (rt->ui.noise_perlin->x +
					rt->ui.noise_perlin->w)) && (y > rt->ui.noise_perlin->y
					&& y < (rt->ui.noise_perlin->y + rt->ui.noise_perlin->h)))
	{
		if (rt->ui.noise_perlin->hovered == 0)
		{
			rt->ui.noise_perlin->hovered = 1;
			update_ui_element(rt,
&rt->ui.noise_perlin, "./assets/interface/noise-perlin-hovered.png");
		}
	}
	else
	{
		if (rt->ui.noise_perlin->hovered == 1)
		{
			rt->ui.noise_perlin->hovered = 0;
			update_ui_element(rt,
&rt->ui.noise_perlin, "./assets/interface/noise-perlin-normal.png");
		}
	}
}

static void	hover_damier(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.noise_damier->x && x < (rt->ui.noise_damier->x +
					rt->ui.noise_damier->w)) && (y > rt->ui.noise_damier->y
					&& y < (rt->ui.noise_damier->y + rt->ui.noise_damier->h)))
	{
		if (rt->ui.noise_damier->hovered == 0)
		{
			rt->ui.noise_damier->hovered = 1;
			update_ui_element(rt,
&rt->ui.noise_damier, "./assets/interface/noise-damier-hovered.png");
		}
	}
	else
	{
		if (rt->ui.noise_damier->hovered == 1)
		{
			rt->ui.noise_damier->hovered = 0;
			update_ui_element(rt,
&rt->ui.noise_damier, "./assets/interface/noise-damier-normal.png");
		}
	}
}

static void	hover_close(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.close->x && x < (rt->ui.close->x +
					rt->ui.close->w)) && (y > rt->ui.close->y
					&& y < (rt->ui.close->y + rt->ui.close->h)))
	{
		if (rt->ui.close->hovered == 0)
		{
			rt->ui.close->hovered = 1;
			update_ui_element(rt,
&rt->ui.close, "./assets/interface/button-tab-close-hovered.png");
		}
	}
	else
	{
		if (rt->ui.close->hovered == 1)
		{
			rt->ui.close->hovered = 0;
			update_ui_element(rt,
&rt->ui.close, "./assets/interface/button-tab-close.png");
		}
	}
}

void		hover(t_rt *rt, int x, int y)
{
	hover_add_sphere(rt, x, y);
	hover_add_cylinder(rt, x, y);
	hover_add_cone(rt, x, y);
	hover_add_plane(rt, x, y);
	hover_none(rt, x, y);
	hover_voronoi(rt, x, y);
	hover_perlin(rt, x, y);
	hover_damier(rt, x, y);
	hover_close(rt, x, y);
}
