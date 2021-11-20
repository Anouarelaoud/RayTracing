/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_props_per_object.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 05:49:16 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 02:31:52 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	check_plane_props(t_rt *rt)
{
	char *accepted[13];
	char *required[2];

	accepted[0] = "position";
	accepted[1] = "normal";
	accepted[2] = "color";
	accepted[3] = "translation";
	accepted[4] = "rotation";
	accepted[5] = "noise";
	accepted[6] = "limitx";
	accepted[7] = "limity";
	accepted[8] = "texture";
	accepted[9] = "texture_slice";
	accepted[10] = "texture_scale";
	accepted[11] = "texture_offset_x";
	accepted[12] = "texture_offset_y";
	required[0] = "position";
	required[1] = "normal";
	check_rt_props(rt, accepted, required, (t_point){13, 2});
}

void	check_sphere_props(t_rt *rt)
{
	char *accepted[13];
	char *required[2];

	accepted[0] = "position";
	accepted[1] = "rayon";
	accepted[2] = "color";
	accepted[3] = "translation";
	accepted[4] = "noise";
	accepted[5] = "sliced";
	accepted[6] = "texture";
	accepted[7] = "texture_scale";
	accepted[8] = "texture_slice";
	accepted[9] = "texture_offset_x";
	accepted[10] = "texture_offset_y";
	accepted[11] = "axe";
	accepted[12] = "rotation";
	required[0] = "position";
	required[1] = "rayon";
	check_rt_props(rt, accepted, required, (t_point){13, 2});
}

void	check_cylinder_props(t_rt *rt)
{
	char *accepted[13];
	char *required[2];

	accepted[0] = "position";
	accepted[1] = "rayon";
	accepted[2] = "axe";
	accepted[3] = "color";
	accepted[4] = "translation";
	accepted[5] = "rotation";
	accepted[6] = "noise";
	accepted[7] = "limit";
	accepted[8] = "texture";
	accepted[9] = "texture_slice";
	accepted[10] = "texture_scale";
	accepted[11] = "texture_offset_x";
	accepted[12] = "texture_offset_y";
	required[0] = "position";
	required[1] = "rayon";
	check_rt_props(rt, accepted, required, (t_point){13, 2});
}

void	check_cone_props(t_rt *rt)
{
	char *accepted[13];
	char *required[2];

	accepted[0] = "position";
	accepted[1] = "axe";
	accepted[2] = "k";
	accepted[3] = "color";
	accepted[4] = "translation";
	accepted[5] = "rotation";
	accepted[6] = "noise";
	accepted[7] = "limit";
	accepted[8] = "texture";
	accepted[9] = "texture_slice";
	accepted[10] = "texture_scale";
	accepted[11] = "texture_offset_x";
	accepted[12] = "texture_offset_y";
	required[0] = "position";
	required[1] = "k";
	check_rt_props(rt, accepted, required, (t_point){13, 2});
}

void	check_torus_props(t_rt *rt)
{
	char *accepted[8];
	char *required[3];

	accepted[0] = "position";
	accepted[1] = "axe";
	accepted[2] = "k";
	accepted[3] = "l";
	accepted[4] = "color";
	accepted[5] = "translation";
	accepted[6] = "rotation";
	accepted[7] = "noise";
	required[0] = "position";
	required[1] = "k";
	required[2] = "l";
	check_rt_props(rt, accepted, required, (t_point){8, 3});
}
