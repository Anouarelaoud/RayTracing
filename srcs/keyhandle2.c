/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:30:05 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 18:30:41 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		mouse_handle(int keycode, int x, int y, t_rt *r)
{
	if (keycode == RIGHT_CLICK)
	{
		if (x >= 126 && y >= 190)
			select_object(r, x, y);
	}
	if (keycode == LEFT_CLICK)
	{
		close_button_event(r, x, y);
		if (r->selected)
		{
			noise_change_event(r, x, y);
			color_change_event(r, x, y);
			deselect_object(r, x, y);
			update_ui(r);
		}
		add_object_event(r, x, y);
	}
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_rt *r;

	r = (t_rt *)param;
	hover(r, x, y);
	return (0);
}
