/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 05:15:28 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 00:39:26 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		get_texture2(t_rt *rt, t_obj *obj, char *key, char *value)
{
	if (ft_strequ(key, "texture_scale"))
	{
		if (obj->color.type != c_texture)
			xml_error(rt, "used texture_scale without texture.");
		obj->txt->hi = xml_int(rt, key, value);
		if (obj->txt->hi < 0)
			xml_error(rt, "texture_scale value invalid (should be positive)");
	}
	else if (ft_strequ(key, "texture_offset_x"))
	{
		if (obj->color.type != c_texture)
			xml_error(rt, "used texture_offset_x without texture.");
		obj->txt->x_offset = xml_int(rt, key, value);
		obj->txt->x_offset =
obj->txt->x_offset == 0 ? 0 : 1.0 / obj->txt->x_offset;
	}
	else if (ft_strequ(key, "texture_offset_y"))
	{
		if (obj->color.type != c_texture)
			xml_error(rt, "used texture_offset_y without texture.");
		obj->txt->y_offset = xml_int(rt, key, value);
		obj->txt->y_offset =
obj->txt->y_offset == 0 ? 0 : 1.0 / obj->txt->y_offset;
	}
}

void			get_texture(t_rt *rt, t_obj *obj, char *key, char *value)
{
	if (ft_strequ(key, "texture"))
	{
		obj->color.type = c_texture;
		if (!(obj->txt = (t_texture *)ft_memalloc(sizeof(t_texture))))
			free_garbage(rt);
		garbage_collector(rt, obj->txt);
		init_texture(obj->txt);
		if (!(obj->txt->path = ft_strdup(value)))
			free_garbage(rt);
		garbage_collector(rt, obj->txt->path);
	}
	else if (ft_strequ(key, "texture_slice"))
	{
		if (obj->color.type != c_texture)
			xml_error(rt, "used texture_slice without texture.");
		if (ft_strequ(value, "true"))
			obj->txt->coup = 1;
		else if (ft_strequ(value, "false"))
			obj->txt->coup = 0;
		else
			xml_error(rt,
"texture_slice value invalid (\"true\" or \"false\")");
	}
	get_texture2(rt, obj, key, value);
}

void			get_texture_props(t_rt *rt, t_obj *obj, char *key, char *value)
{
	if (ft_strequ(key, "texture") || ft_strequ(key, "texture_slice") ||
ft_strequ(key, "texture_scale") || ft_strequ(key, "texture_offset_x") ||
ft_strequ(key, "texture_offset_y"))
		get_texture(rt, obj, key, value);
}
