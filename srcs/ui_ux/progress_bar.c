/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_bar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 04:28:06 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 03:50:53 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	update_progressbar(t_rt *rt, double percent)
{
	t_point		p;

	if (rt->ui.activate_pb)
	{
		p = (t_point){.x = (int)(rt->ui.last_progress * PB_H), .y = 0};
		while (p.x < (int)((rt->ui.last_progress + percent) * PB_W))
		{
			p.y = 0;
			while (p.y < PB_H)
			{
				rt->ui.pb->d.pic_str[(int)(p.y * PB_W + p.x)] = 0x00ff00;
				p.y++;
			}
			p.x++;
		}
		mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.pb->ptr,
		PB_X, PB_Y);
		mlx_do_sync(rt->mlx.ptr);
	}
}
