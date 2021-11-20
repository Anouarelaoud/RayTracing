/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hover2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 04:01:15 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/11 04:58:18 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hover_add_sphere(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.add_sphere->x && x < (rt->ui.add_sphere->x +
					rt->ui.add_sphere->w)) && (y > rt->ui.add_sphere->y
					&& y < (rt->ui.add_sphere->y + rt->ui.add_sphere->h)))
	{
		if (rt->ui.add_sphere->hovered == 0)
		{
			rt->ui.add_sphere->hovered = 1;
			update_ui_element(rt,
&rt->ui.add_sphere, "./assets/interface/button-add-sphere-hovered.png");
		}
	}
	else
	{
		if (rt->ui.add_sphere->hovered == 1)
		{
			rt->ui.add_sphere->hovered = 0;
			update_ui_element(rt,
&rt->ui.add_sphere, "./assets/interface/button-add-sphere-normal.png");
		}
	}
}

void	hover_add_cylinder(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.add_cylinder->x && x < (rt->ui.add_cylinder->x +
					rt->ui.add_cylinder->w)) && (y > rt->ui.add_cylinder->y
					&& y < (rt->ui.add_cylinder->y + rt->ui.add_cylinder->h)))
	{
		if (rt->ui.add_cylinder->hovered == 0)
		{
			rt->ui.add_cylinder->hovered = 1;
			update_ui_element(rt,
&rt->ui.add_cylinder, "./assets/interface/button-add-cylinder-hovered.png");
		}
	}
	else
	{
		if (rt->ui.add_cylinder->hovered == 1)
		{
			rt->ui.add_cylinder->hovered = 0;
			update_ui_element(rt,
&rt->ui.add_cylinder, "./assets/interface/button-add-cylinder-normal.png");
		}
	}
}

void	hover_add_cone(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.add_cone->x && x < (rt->ui.add_cone->x +
					rt->ui.add_cone->w)) && (y > rt->ui.add_cone->y
					&& y < (rt->ui.add_cone->y + rt->ui.add_cone->h)))
	{
		if (rt->ui.add_cone->hovered == 0)
		{
			rt->ui.add_cone->hovered = 1;
			update_ui_element(rt,
&rt->ui.add_cone, "./assets/interface/button-add-cone-hovered.png");
		}
	}
	else
	{
		if (rt->ui.add_cone->hovered == 1)
		{
			rt->ui.add_cone->hovered = 0;
			update_ui_element(rt,
&rt->ui.add_cone, "./assets/interface/button-add-cone-normal.png");
		}
	}
}

void	hover_add_plane(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.add_plane->x && x < (rt->ui.add_plane->x +
					rt->ui.add_plane->w)) && (y > rt->ui.add_plane->y
					&& y < (rt->ui.add_plane->y + rt->ui.add_plane->h)))
	{
		if (rt->ui.add_plane->hovered == 0)
		{
			rt->ui.add_plane->hovered = 1;
			update_ui_element(rt,
&rt->ui.add_plane, "./assets/interface/button-add-plane-hovered.png");
		}
	}
	else
	{
		if (rt->ui.add_plane->hovered == 1)
		{
			rt->ui.add_plane->hovered = 0;
			update_ui_element(rt,
&rt->ui.add_plane, "./assets/interface/button-add-plane-normal.png");
		}
	}
}

void	hover_none(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.none->x && x < (rt->ui.none->x +
					rt->ui.none->w)) && (y > rt->ui.none->y
					&& y < (rt->ui.none->y + rt->ui.none->h)))
	{
		if (rt->ui.none->hovered == 0)
		{
			rt->ui.none->hovered = 1;
			update_ui_element(rt,
&rt->ui.none, "./assets/interface/none-hovered.png");
		}
	}
	else
	{
		if (rt->ui.none->hovered == 1)
		{
			rt->ui.none->hovered = 0;
			update_ui_element(rt,
&rt->ui.none, "./assets/interface/none-normal.png");
		}
	}
}
