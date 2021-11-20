/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:43:09 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 16:43:32 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		get_axes(t_obj *obj, t_vecteur p)
{
	if (obj->type == tsphere)
		return (getanglesphere(obj, p));
	else if (obj->type == tcylinder)
		return (getanglecylinder(obj, p));
	else if (obj->type == tcone)
		return (getanglecone(obj, p));
	return (getangleplan(obj, p));
}

t_color	checkerboard(t_obj *obj, t_vecteur p)
{
	t_color		new;
	double		pro_i;
	double		pro_j;

	new.r = 0;
	new.g = 0;
	new.b = 0;
	get_axes(obj, p);
	pro_i = floor(obj->txt->um * 10.0);
	pro_j = floor(obj->txt->vm * 10.0);
	if ((fmod(pro_i, 2.0) == 0.0 && fmod(pro_j, 2.0) == 0.0) ||
		(fmod(pro_i, 2.0) != 0.0 && fmod(pro_j, 2.0) != 0.0))
	{
		new.r = 255;
		new.g = 255;
		new.b = 255;
	}
	return (new);
}
