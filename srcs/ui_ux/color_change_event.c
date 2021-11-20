/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_change_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 03:52:00 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 05:08:12 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		apply_noise(t_rt *rt, int noise)
{
	t_obj *head;

	head = rt->selected;
	if (noise == n_damier)
	{
		while (rt->selected)
		{
			rt->selected->noise = n_damier;
			if (!(rt->selected->txt =
(t_texture *)ft_memalloc(sizeof(t_texture))))
				free_garbage(rt);
			garbage_collector(rt, rt->selected->txt);
			init_texture(rt->selected->txt);
			rt->selected = rt->selected->next;
		}
	}
	else
	{
		while (rt->selected)
		{
			rt->selected->noise = noise;
			rt->selected = rt->selected->next;
		}
	}
	rt->selected = head;
}

void		init_obj_list(t_obj **obj, t_rt *rt)
{
	if (!rt->last_obj)
	{
		rt->obj_list = (t_obj *)ft_memalloc(sizeof(t_obj));
		if (!rt->obj_list)
			free_garbage(rt);
		garbage_collector(rt, rt->obj_list);
		(*obj) = rt->obj_list;
		rt->head = (*obj);
	}
	else
	{
		rt->last_obj->next = (t_obj *)ft_memalloc(sizeof(t_obj));
		if (!rt->last_obj->next)
			free_garbage(rt);
		garbage_collector(rt, rt->last_obj->next);
		(*obj) = rt->last_obj->next;
	}
}

void		close_button_event(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.close->x && x < (rt->ui.close->x +
rt->ui.close->w)) && (y > rt->ui.close->y &&
y < (rt->ui.close->y + rt->ui.close->h)))
		ft_close(rt);
}

void		color_change_event(t_rt *rt, int x, int y)
{
	int		color;
	t_obj	*head;

	if ((x > rt->ui.color_wheel->x && x < (rt->ui.color_wheel->x +
rt->ui.color_wheel->w)) && (y > rt->ui.color_wheel->y &&
y < (rt->ui.color_wheel->y + rt->ui.color_wheel->h)))
	{
		color = rt->ui.color_wheel->d.pic_str[(y - rt->ui.color_wheel->y) *
rt->ui.color_wheel->w + (x - rt->ui.color_wheel->x)];
		head = rt->selected;
		while (rt->selected)
		{
			rt->selected->color =
(t_color){.r = r(color), .g = g(color), .b = b(color)};
			rt->selected = rt->selected->next;
		}
		rt->selected = head;
		rt->ui.activate_pb = 0;
		raytracer(rt);
	}
}
