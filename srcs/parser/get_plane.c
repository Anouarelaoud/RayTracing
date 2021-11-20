/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 06:37:18 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 00:37:16 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	slice_plane(t_rt *rt, t_obj *obj, char *key, char *value)
{
	obj->sliced = 1;
	if (ft_strequ(key, "limitx"))
	{
		obj->limitx = xml_float_or_percentage(rt, key, value);
		if (obj->limitx < 0)
			xml_error(rt, "Invalid value for limitx");
	}
	else
	{
		obj->limitz = xml_float_or_percentage(rt, key, value);
		if (obj->limitz < 0)
			xml_error(rt, "Invalid value for limity");
	}
}

void		get_plane(t_rt *rt, t_obj **obj)
{
	t_xml_object	*xobj;
	int				nb;

	xobj = rt->xml->obj_list;
	xobj->props = xobj->head_props;
	nb = xobj->nb_props;
	(*obj)->color = (t_color){.type = c_default, .r = 0, .g = 255, .b = 255};
	while (nb--)
	{
		get_standard_props(rt, xobj->props->key, xobj->props->value, obj);
		if (ft_strequ(xobj->props->key, "normal"))
			(*obj)->axe = xml_vector(rt, xobj->props->key, xobj->props->value);
		else if (ft_strequ(xobj->props->key, "limitx") ||
ft_strequ(xobj->props->key, "limity"))
			slice_plane(rt, *obj, xobj->props->key, xobj->props->value);
		get_texture_props(rt, *obj, xobj->props->key, xobj->props->value);
		xobj->props = xobj->props->next;
	}
	if ((*obj)->sliced && ((*obj)->limitz < 0 || (*obj)->limitx < 0))
		xml_error(rt, "Make sure u entered both limitx and limity values");
	if ((*obj)->sliced && (*obj)->color.type == c_texture)
		xml_error(rt, "Cannot apply texture on sliced objects.");
}
