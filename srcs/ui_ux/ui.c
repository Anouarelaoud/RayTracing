/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 04:32:58 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 23:45:02 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			init_ui_element(t_rt *rt, t_ui_element **e, t_coor c, char *p)
{
	(*e) = (t_ui_element *)malloc(sizeof(t_ui_element));
	if (!(*e))
		free_garbage(rt);
	garbage_collector(rt, (*e));
	(*e)->x = c.x;
	(*e)->y = c.y;
	(*e)->w = c.w;
	(*e)->h = c.h;
	(*e)->hovered = 0;
	(*e)->ptr = mlx_png_file_to_image(rt->mlx.ptr, p, &(*e)->w, &(*e)->h);
	(*e)->d.pic_str = (int *)mlx_get_data_addr((*e)->ptr, &(*e)->d.bpp,
&(*e)->d.s_l, &(*e)->d.endian);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, (*e)->ptr,
(*e)->x, (*e)->y);
}

static void		init_ui(t_rt *rt)
{
	init_ui_element(rt, &rt->ui.toolbar_top, (t_coor){.x = -5, .y = -5,
.w = 1930, .h = 121}, "./assets/interface/toolbar-top.png");
	init_ui_element(rt, &rt->ui.toolbar_left, (t_coor){.x = -5,
.y = 111, .w = 126, .h = 973}, "./assets/interface/toolbar-left.png");
	init_ui_element(rt, &rt->ui.logo_small, (t_coor){.x = 20, .y = 22, .w = 66,
.h = 66}, "./assets/interface/logo-small.png");
	init_ui_element(rt, &rt->ui.tab_bar, (t_coor){.x = 120, .y = 116,
.w = 1805, .h = 68}, "./assets/interface/tabbar.png");
	init_ui_element(rt, &rt->ui.tab, (t_coor){.x = 120, .y = 116, .w = 588,
.h = 68}, "./assets/interface/tab.png");
	init_ui_element(rt, &rt->ui.add_sphere, (t_coor){.x = 5, .y = 124, .w = 97,
.h = 104}, "./assets/interface/button-add-sphere-normal.png");
	init_ui_element(rt, &rt->ui.add_cylinder, (t_coor){.x = 5, .y = 233,
.w = 97, .h = 104}, "./assets/interface/button-add-cylinder-normal.png");
	init_ui_element(rt, &rt->ui.add_cone, (t_coor){.x = 5, .y = 342, .w = 97,
.h = 104}, "./assets/interface/button-add-cone-normal.png");
	init_ui_element(rt, &rt->ui.add_plane, (t_coor){.x = 5, .y = 451, .w = 97,
.h = 104}, "./assets/interface/button-add-plane-normal.png");
	init_ui_element(rt, &rt->ui.selected, (t_coor){.x = 150, .y = 40, .w = 303,
.h = 33}, "./assets/interface/selected.png");
	init_ui_element(rt, &rt->ui.none, (t_coor){.x = 670, .y = 28, .w = 55,
.h = 55}, "./assets/interface/none-normal.png");
	init_ui_element(rt, &rt->ui.noise_voronoi, (t_coor){.x = 730, .y = 28,
.w = 55, .h = 55}, "./assets/interface/noise-voronoi-normal.png");
}

static void		init_ui2(t_rt *rt)
{
	init_ui_element(rt, &rt->ui.noise_perlin, (t_coor){.x = 790, .y = 28,
.w = 55, .h = 55}, "./assets/interface/noise-perlin-normal.png");
	init_ui_element(rt, &rt->ui.noise_damier, (t_coor){.x = 850, .y = 28,
.w = 55, .h = 55}, "./assets/interface/noise-damier-normal.png");
	init_ui_element(rt, &rt->ui.close, (t_coor){.x = 665, .y = 138, .w = 23,
.h = 23}, "./assets/interface/button-tab-close.png");
	init_ui_element(rt, &rt->ui.color_wheel, (t_coor){1300, 15, 23, 23},
"./assets/interface/color-wheel.png");
	mlx_string_put(rt->mlx.ptr, rt->mlx.win, 140, 156, 0xffffff, ft_strjoin(
rt->name, ft_strjoin(" @ ", ft_strjoin(ft_itoa((int)(rt->res * 100)), "%"))));
	rt->ui.pb = (t_ui_element *)malloc(sizeof(t_ui_element));
	if (!rt->ui.pb)
		free_garbage(rt);
	garbage_collector(rt, rt->ui.pb);
	rt->ui.pb->ptr = mlx_new_image(rt->mlx.ptr, PB_W, PB_H);
	rt->ui.pb->d.pic_str = (int *)mlx_get_data_addr(rt->ui.pb->ptr,
&rt->ui.pb->d.bpp, &rt->ui.pb->d.s_l, &rt->ui.pb->d.endian);
	rt->ui.activate_pb = 0;
}

void			update_ui_element(t_rt *rt, t_ui_element **e, char *path)
{
	ft_bzero((*e)->d.pic_str, (*e)->w * (*e)->h * 4);
	(*e)->ptr = mlx_png_file_to_image(rt->mlx.ptr, path, &(*e)->w, &(*e)->h);
	(*e)->d.pic_str = (int *)mlx_get_data_addr((*e)->ptr, &(*e)->d.bpp,
&(*e)->d.s_l, &(*e)->d.endian);
	update_ui(rt);
}

void			ui(t_rt *rt)
{
	init_ui(rt);
	init_ui2(rt);
	mlx_do_sync(rt->mlx.ptr);
}
