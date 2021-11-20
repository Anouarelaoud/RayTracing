/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 01:58:49 by mderri            #+#    #+#             */
/*   Updated: 2020/11/12 05:09:49 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	helper1(t_rt *rt, int type)
{
	if (type == thyperboloid)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, WHITE, "Hyperboloid");
	else if (type == tcubet)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, WHITE, "Cube troué");
	else if (type == tmoebius)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, WHITE, "Moebius");
	else if (type == tdingdong)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, WHITE, "Dingdong");
	else if (type == tgoursat)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, WHITE, "Goursat");
	else if (type == tteardrop)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, WHITE, "Teardrop");
}

static void	write_selected(t_rt *rt)
{
	int	type;

	type = rt->selected->type;
	if (type == tplane)
	{
		if (rt->selected->parent->type == tcube)
			mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, WHITE, "Cube");
		else
			mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, WHITE, "Plane");
	}
	else if (type == tsphere)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, WHITE, "Sphere");
	else if (type == tcylinder)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, WHITE, "Cylinder");
	else if (type == tcone)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, WHITE, "Cone");
	else if (type == ttorus)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, WHITE, "Torus");
	else if (type == tparaboloid)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, WHITE, "Paraboloid");
	else if (type == tellipsoid)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, WHITE, "Ellipsoid");
	else
		helper1(rt, type);
}

static void	write_selected_coordinates(t_rt *rt)
{
	mlx_string_put(rt->mlx.ptr, rt->mlx.win, 255, 95, 0,
	"x =");
	mlx_string_put(rt->mlx.ptr, rt->mlx.win, 282, 95, 0xffffff,
	ft_itoa((int)rt->selected->pos.x));
	mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 95, 0,
	"y =");
	mlx_string_put(rt->mlx.ptr, rt->mlx.win, 362, 95, 0xffffff,
	ft_itoa((int)rt->selected->pos.y));
	mlx_string_put(rt->mlx.ptr, rt->mlx.win, 415, 95, 0,
	"z =");
	mlx_string_put(rt->mlx.ptr, rt->mlx.win, 442, 95, 0xffffff,
	ft_itoa((int)rt->selected->pos.z));
}

void		update_ui(t_rt *rt)
{
	put_images(rt);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->mlx.d.img_ptr,
126, 190);
	mlx_string_put(rt->mlx.ptr, rt->mlx.win, 140, 156, 0xffffff,
ft_strjoin(rt->name, ft_strjoin(" @ ",
ft_strjoin(ft_itoa((int)(rt->res * 100)), "%"))));
	if (rt->selected)
	{
		write_selected(rt);
		write_selected_coordinates(rt);
	}
}
