/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:56:19 by erahimi           #+#    #+#             */
/*   Updated: 2020/11/12 16:47:31 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		mb_loop(t_rt *rt, t_loop *loop, t_loop *filter, t_vecteur *c)
{
	t_loop	img;

	img.i = (int)(loop->i - FILTER_MB_W / 2 + filter->i + rt->mlx.w)
		% rt->mlx.w;
	img.j = (int)(loop->j - FILTER_MB_H / 2 + filter->j + rt->mlx.h)
		% rt->mlx.h;
	c->x += r(rt->mlx.d.pic_str[img.j * rt->mlx.w + img.i])
		* (filter->i == filter->j ? 1 : 0);
	c->y += g(rt->mlx.d.pic_str[img.j * rt->mlx.w + img.i])
		* (filter->i == filter->j ? 1 : 0);
	c->z += b(rt->mlx.d.pic_str[img.j * rt->mlx.w + img.i])
		* (filter->i == filter->j ? 1 : 0);
}

void			ft_filter_mb(t_rt *rt)
{
	t_loop		loop;
	t_loop		filter;
	t_vecteur	c;

	loop.i = -1;
	while (++loop.i < rt->mlx.w)
	{
		loop.j = -1;
		while (++loop.j < rt->mlx.h)
		{
			c = create_v(0.0, 0.0, 0.0);
			filter.j = -1;
			while (++filter.j < FILTER_MB_H)
			{
				filter.i = -1;
				while (++filter.i < FILTER_MB_W)
					mb_loop(rt, &loop, &filter, &c);
				rt->mlx.d.pic_str[loop.j * (int)rt->mlx.w + loop.i] =
					rgb_int(clamp((int)(c.x / 9.0), 255.0, 0.0),
							clamp((int)(c.y / 9.0), 255.0, 0.0),
							clamp((int)(c.z / 9.0), 255.0, 0.0));
			}
		}
	}
}
