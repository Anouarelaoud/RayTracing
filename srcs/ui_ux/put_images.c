/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 04:49:25 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/11 04:49:53 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	helper2(t_rt *rt)
{
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.add_plane->ptr,
rt->ui.add_plane->x, rt->ui.add_plane->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.selected->ptr,
rt->ui.selected->x, rt->ui.selected->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.none->ptr,
rt->ui.none->x, rt->ui.none->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.noise_voronoi->ptr,
rt->ui.noise_voronoi->x, rt->ui.noise_voronoi->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.noise_perlin->ptr,
rt->ui.noise_perlin->x, rt->ui.noise_perlin->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.noise_damier->ptr,
rt->ui.noise_damier->x, rt->ui.noise_damier->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.close->ptr,
rt->ui.close->x, rt->ui.close->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.color_wheel->ptr,
rt->ui.color_wheel->x, rt->ui.color_wheel->y);
}

void		put_images(t_rt *rt)
{
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.toolbar_top->ptr,
rt->ui.toolbar_top->x, rt->ui.toolbar_top->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.toolbar_left->ptr,
rt->ui.toolbar_left->x, rt->ui.toolbar_left->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.tab_bar->ptr,
rt->ui.tab_bar->x, rt->ui.tab_bar->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.tab->ptr,
rt->ui.tab->x, rt->ui.tab->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.logo_small->ptr,
rt->ui.logo_small->x, rt->ui.logo_small->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.add_sphere->ptr,
rt->ui.add_sphere->x, rt->ui.add_sphere->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.add_cylinder->ptr,
rt->ui.add_cylinder->x, rt->ui.add_cylinder->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.add_cone->ptr,
rt->ui.add_cone->x, rt->ui.add_cone->y);
	helper2(rt);
}
