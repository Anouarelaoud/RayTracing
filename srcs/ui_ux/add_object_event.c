/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 03:45:51 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 05:08:03 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	add_sphere_event(t_rt *rt, int x, int y)
{
	t_obj *obj;

	if ((x > rt->ui.add_sphere->x && x < (rt->ui.add_sphere->x +
rt->ui.add_sphere->w)) && (y > rt->ui.add_sphere->y &&
y < (rt->ui.add_sphere->y + rt->ui.add_sphere->h)))
	{
		init_obj_list(&obj, rt);
		obj->type = tsphere;
		obj->k = 5;
		obj->pos = (t_vecteur){.x = 0, .y = 0, .z = 0};
		obj->noise = n_none;
		obj->color = (t_color){.r = 0, .g = 255, .b = 0};
		obj->rot = (t_vecteur){0, 0, 0};
		obj->tr = (t_vecteur){0, 0, 0};
		obj->axe = create_v(0, -1, 0);
		project_obj(&obj, tsphere);
		add_compos(rt, obj);
		obj->next = NULL;
		rt->last_obj = obj;
		rt->selected = obj->head_compos;
		raytracer(rt);
	}
}

static void	add_cylinder_event(t_rt *rt, int x, int y)
{
	t_obj *obj;

	if ((x > rt->ui.add_cylinder->x && x < (rt->ui.add_cylinder->x +
					rt->ui.add_cylinder->w)) && (y > rt->ui.add_cylinder->y
					&& y < (rt->ui.add_cylinder->y + rt->ui.add_cylinder->h)))
	{
		init_obj_list(&obj, rt);
		obj->type = tcylinder;
		obj->k = 3;
		obj->pos = (t_vecteur){.x = 0, .y = 0, .z = 0};
		obj->noise = n_none;
		obj->color = (t_color){.r = 0, .g = 0, .b = 225};
		obj->rot = (t_vecteur){0, 0, 0};
		obj->tr = (t_vecteur){0, 0, 0};
		obj->axe = create_v(0, -1, 0);
		add_compos(rt, obj);
		obj->next = NULL;
		rt->last_obj = obj;
		rt->selected = obj->head_compos;
		raytracer(rt);
	}
}

static void	add_cone_event(t_rt *rt, int x, int y)
{
	t_obj *obj;

	if ((x > rt->ui.add_cone->x && x < (rt->ui.add_cone->x +
					rt->ui.add_cone->w)) && (y > rt->ui.add_cone->y
					&& y < (rt->ui.add_cone->y + rt->ui.add_cone->h)))
	{
		init_obj_list(&obj, rt);
		obj->type = tcone;
		obj->k = .3;
		obj->pos = (t_vecteur){.x = 0, .y = 0, .z = 0};
		obj->noise = n_none;
		obj->color = (t_color){.r = 255, .g = 0, .b = 0};
		obj->rot = (t_vecteur){0, 0, 0};
		obj->tr = (t_vecteur){0, 0, 0};
		obj->axe = create_v(0, -1, 0);
		add_compos(rt, obj);
		obj->next = NULL;
		rt->last_obj = obj;
		rt->selected = obj->head_compos;
		raytracer(rt);
	}
}

static void	add_plane_event(t_rt *rt, int x, int y)
{
	t_obj *obj;

	if ((x > rt->ui.add_plane->x && x < (rt->ui.add_plane->x +
					rt->ui.add_plane->w)) && (y > rt->ui.add_plane->y
					&& y < (rt->ui.add_plane->y + rt->ui.add_plane->h)))
	{
		init_obj_list(&obj, rt);
		obj->type = tplane;
		obj->pos = (t_vecteur){.x = 0, .y = 10, .z = 0};
		obj->noise = n_none;
		obj->color = (t_color){.r = 0, .g = 255, .b = 255};
		obj->rot = (t_vecteur){0, 0, 0};
		obj->tr = (t_vecteur){0, 0, 0};
		obj->axe = create_v(0, 1, 0);
		add_compos(rt, obj);
		obj->next = NULL;
		rt->last_obj = obj;
		rt->selected = obj->head_compos;
		raytracer(rt);
	}
}

void		add_object_event(t_rt *r, int x, int y)
{
	add_sphere_event(r, x, y);
	add_cylinder_event(r, x, y);
	add_cone_event(r, x, y);
	add_plane_event(r, x, y);
}
