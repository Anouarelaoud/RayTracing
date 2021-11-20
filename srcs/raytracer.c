/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:32:07 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 01:33:28 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				cast_object(t_rt *r)
{
	t_obj		*obj;
	t_obj		*compos;

	obj = r->head;
	r->obj = NULL;
	while (obj)
	{
		compos = obj->head_compos;
		while (compos)
		{
			if (compos->type == tplane)
				rat_trace_plane(r, compos);
			else if (compos->type == tsphere)
				rat_trace_sphere(r, compos);
			else if (compos->type == tcylinder)
				rat_trace_cylinder(r, compos);
			else
				cast_object_help(r, compos);
			compos = compos->next;
		}
		obj = obj->next;
	}
	if (r->obj)
		return (1);
	return (0);
}

static void		assign_colors(t_rt *r, int res)
{
	t_point p;

	p.y = r->v1.y;
	while (p.y < r->v1.y + res)
	{
		p.x = r->v1.x;
		while (p.x < r->v1.x + res)
		{
			r->mlx.d.pic_str[(int)(p.y * r->mlx.w + p.x)] =
	rgb(r->color.r, r->color.g, r->color.b);
			p.x++;
		}
		p.y++;
	}
}

void			raytracer_aliasing(t_rt *r)
{
	int		res;

	res = 1 / r->res;
	while (r->v1.y < r->mlx.h)
	{
		r->v1.x = 0;
		while (r->v1.x < r->mlx.w)
		{
			r->v2 = r->v1;
			make_ray(r);
			r->u = normalise(r->ray.direct);
			r->dis = MAX;
			if (cast_object(r))
			{
				lighting(r);
				assign_colors(r, res);
			}
			r->v1.x += res;
		}
		r->ui.current_progress = ((r->v1.x + 1) * (r->v1.y + 1)) /
		(r->mlx.w * r->mlx.h);
		update_progressbar(r, r->ui.current_progress - r->ui.last_progress);
		r->ui.last_progress = r->ui.current_progress;
		r->v1.y += res;
	}
}

void			raytracer_anti_aliasing(t_rt *rt)
{
	t_color	color;

	color = (t_color){.type = c_default, .r = 0, .g = 0, .b = 0};
	rt->v2.y = (int)(rt->v1.y * rt->res) - 1;
	while (++(rt->v2.y) < (rt->v1.y * (int)rt->res + (int)rt->res))
	{
		rt->v2.x = (int)(rt->v1.x * rt->res);
		while (rt->v2.x < (rt->v1.x * (int)rt->res + (int)rt->res))
		{
			make_ray(rt);
			rt->u = normalise(rt->ray.direct);
			rt->dis = MAX;
			if (cast_object(rt))
			{
				lighting(rt);
				color.r += rt->color.r;
				color.g += rt->color.g;
				color.b += rt->color.b;
			}
			rt->v2.x++;
		}
	}
	rt->mlx.d.pic_str[(int)(rt->v1.y * rt->mlx.w + rt->v1.x)] =
	rgb((int)(color.r / (rt->res * rt->res)), (int)(color.g /
	(rt->res * rt->res)), (int)(color.b / (rt->res * rt->res)));
}

void			raytracer(t_rt *r)
{
	ft_bzero(r->mlx.d.pic_str, r->mlx.w * r->mlx.h * 4);
	r->v1.y = 0;
	if (r->res >= 1)
		while (r->v1.y < r->mlx.h)
		{
			r->v1.x = -1;
			while (++(r->v1.x) < r->mlx.w)
			{
				raytracer_anti_aliasing(r);
			}
			r->ui.current_progress = ((r->v1.x + 1) * (r->v1.y + 1)) /
			(r->mlx.w * r->mlx.h);
			update_progressbar(r, r->ui.current_progress - r->ui.last_progress);
			r->ui.last_progress = r->ui.current_progress;
			r->v1.y++;
		}
	else
		raytracer_aliasing(r);
	filtre(r);
	mlx_put_image_to_window(r->mlx.ptr, r->mlx.win, r->mlx.d.img_ptr,
	RENDER_X, RENDER_Y);
	r->ui.current_progress = 0;
	r->ui.last_progress = 0;
	ft_bzero(r->ui.pb->d.pic_str, PB_H * PB_W * 4);
	r->ui.activate_pb = 1;
}
