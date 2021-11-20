/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_props_per_object_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 06:29:44 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/11 23:24:12 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	check_paraboloid_props(t_rt *rt)
{
	char *accepted[7];
	char *required[3];

	accepted[0] = "position";
	accepted[1] = "k";
	accepted[2] = "axe";
	accepted[3] = "color";
	accepted[4] = "translation";
	accepted[5] = "rotation";
	accepted[6] = "noise";
	required[0] = "position";
	required[1] = "axe";
	required[2] = "k";
	check_rt_props(rt, accepted, required, (t_point){7, 3});
}

void	check_cubet_props(t_rt *rt)
{
	char *accepted[4];
	char *required[1];

	accepted[0] = "position";
	accepted[1] = "color";
	accepted[2] = "translation";
	accepted[3] = "noise";
	required[0] = "position";
	check_rt_props(rt, accepted, required, (t_point){4, 1});
}

void	check_ellipsoid_props(t_rt *rt)
{
	char *accepted[5];
	char *required[2];

	accepted[0] = "position";
	accepted[1] = "parameters";
	accepted[2] = "color";
	accepted[3] = "translation";
	accepted[4] = "noise";
	required[0] = "position";
	required[1] = "parameters";
	check_rt_props(rt, accepted, required, (t_point){5, 2});
}

void	check_moebius_props(t_rt *rt)
{
	char *accepted[4];
	char *required[1];

	accepted[0] = "k";
	accepted[1] = "color";
	accepted[2] = "translation";
	accepted[3] = "noise";
	required[0] = "k";
	check_rt_props(rt, accepted, required, (t_point){4, 1});
}

void	check_cube_props(t_rt *rt)
{
	char *accepted[7];
	char *required[3];

	accepted[0] = "position";
	accepted[1] = "color";
	accepted[2] = "translation";
	accepted[3] = "rotation";
	accepted[4] = "axe";
	accepted[5] = "noise";
	accepted[6] = "k";
	required[0] = "position";
	required[1] = "axe";
	required[2] = "k";
	check_rt_props(rt, accepted, required, (t_point){7, 3});
}
