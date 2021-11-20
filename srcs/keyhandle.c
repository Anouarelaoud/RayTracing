/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:21:38 by mderri            #+#    #+#             */
/*   Updated: 2020/11/12 18:44:16 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_close(t_rt *r)
{
	mlx_destroy_image(r->mlx.ptr, r->mlx.d.img_ptr);
	mlx_destroy_window(r->mlx.ptr, r->mlx.win);
	free_garbage(r);
	return (0);
}

void	move_selected(t_rt *rt, int vect, long double factor)
{
	t_obj	*obj;
	t_obj	*head;

	obj = rt->selected;
	head = rt->selected;
	while (obj)
	{
		if (vect == 0)
			obj->pos.x += factor;
		if (vect == 1)
			obj->pos.y += factor;
		if (vect == 2)
			obj->pos.z += factor;
		obj = obj->next;
	}
	rt->selected = head;
}

void	change_aliasing(t_rt *r, int key)
{
	if ((r->res * 2) >= 1 && key == PLUS)
	{
		if ((int)(r->res * 2) <= 2)
		{
			r->res = fmin((int)(r->res * 2), 2);
			raytracer(r);
			update_ui(r);
		}
		else
			r->res = fmin((int)(r->res * 2), 2);
	}
	else if (key == PLUS)
	{
		r->res = fmin((r->res * 2), 2);
		raytracer(r);
		update_ui(r);
	}
	if ((r->res / 2) >= .25f && key == MINUS)
	{
		r->res = fmax(0.25, r->res / 2);
		raytracer(r);
		update_ui(r);
	}
	else if (key == MINUS)
		r->res = fmax(0.25, r->res / 2);
}

int		key_press_handle(int keycode, t_rt *r)
{
	(keycode == ESC) ? ft_close(r) : 0;
	if (keycode == UP || keycode == DOWN || keycode == LEFT ||
keycode == RIGHT || keycode == FORWARD || keycode == BACKWARD)
	{
		if (r->selected)
		{
			if (keycode == UP)
				move_selected(r, 1, -r->move_factor);
			if (keycode == DOWN)
				move_selected(r, 1, r->move_factor);
			if (keycode == LEFT)
				move_selected(r, 0, -r->move_factor);
			if (keycode == RIGHT)
				move_selected(r, 0, r->move_factor);
			if (keycode == FORWARD)
				move_selected(r, 2, r->move_factor);
			if (keycode == BACKWARD)
				move_selected(r, 2, -r->move_factor);
			update_ui(r);
			r->ui.activate_pb = 0;
			raytracer(r);
		}
	}
	(keycode == PLUS || keycode == MINUS) ? change_aliasing(r, keycode) : 0;
	return (0);
}

void	deselect_object(t_rt *rt, int x, int y)
{
	if ((x > RENDER_X && x < (RENDER_X + RENDER_W))
	&& (y > RENDER_Y && y < (RENDER_Y + RENDER_H)))
		rt->selected = NULL;
}
