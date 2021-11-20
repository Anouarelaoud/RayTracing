/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 01:09:29 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/13 02:57:48 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			basic_test(char *str)
{
	int i;

	i = ft_strlen(str);
	if (str[i - 1] == '.')
		return (0);
	return (1);
}

void		init_perlin(t_rt *rt)
{
	int i;

	if (!(rt->ran = (t_vecteur *)malloc(256 * sizeof(t_vecteur))))
		free_garbage(rt);
	garbage_collector(rt, rt->ran);
	i = 0;
	while (i < 256)
	{
		rt->ran[i].x = rand() % 255;
		rt->ran[i].y = rand() % 255;
		rt->ran[i].z = rand() % 255;
		rt->ran[i] = normalise(rt->ran[i]);
		rt->hash[i] = rand() % 255;
		i++;
	}
}

void		init_rt(t_rt *rt)
{
	rt->name = ft_strdup("RT lmel3ouna");
	if (!rt->name)
		free_garbage(rt);
	garbage_collector(rt, rt->name);
	rt->xml = (t_xml_helper *)ft_memalloc(sizeof(t_xml_helper));
	if (!rt->xml)
		free_garbage(rt);
	garbage_collector(rt, rt->xml);
	rt->last_obj = NULL;
	rt->last_light = NULL;
	rt->obj_list = NULL;
	rt->light = NULL;
	rt->selected = NULL;
	rt->move_factor = 1;
	rt->mlx.w = RENDER_W;
	rt->mlx.h = RENDER_H;
	init_perlin(rt);
}

void		mlx_event_hook(t_rt *r)
{
	mlx_do_key_autorepeaton(r->mlx.ptr);
	mlx_hook(r->mlx.win, 2, KEYPRESSMASK, key_press_handle, r);
	mlx_hook(r->mlx.win, 6, 0, mouse_move, r);
	mlx_hook(r->mlx.win, 4, 0, mouse_handle, r);
	mlx_hook(r->mlx.win, 17, 1, ft_close, r);
}

int			main(int argc, char **argv)
{
	t_rt		r;

	if (argc != 2)
	{
		ft_putstr("Usage : ./rtv1 scene\n");
		exit(0);
	}
	init_rt(&r);
	xml_parse(argv[1], &r);
	r.head = r.obj_list;
	r.mlx.ptr = mlx_init();
	r.mlx.win = mlx_new_window(r.mlx.ptr, WIDTH, HEIGHT, r.name);
	r.mlx.d.img_ptr = mlx_new_image(r.mlx.ptr, r.mlx.w, r.mlx.h);
	r.mlx.d.pic_str = (int *)mlx_get_data_addr(r.mlx.d.img_ptr, &r.mlx.d.bpp,
&r.mlx.d.s_l, &r.mlx.d.endian);
	texture(&r);
	create_camera(&r);
	ui(&r);
	raytracer(&r);
	mlx_event_hook(&r);
	mlx_loop(r.mlx.ptr);
	return (0);
}
