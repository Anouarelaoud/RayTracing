/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rt_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 06:39:33 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 00:41:15 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		get_flashlight(t_rt *rt, t_light_lst *l, char *key, char *value)
{
	l->type = lt_flashlight;
	if (ft_strequ(key, "axis"))
	{
		l->axis_exists = 1;
		l->axis = xml_vector(rt, key, value);
	}
	else if (ft_strequ(key, "angle"))
	{
		l->angle = xml_float_or_percentage(rt, key, value);
		if (l->angle < 0)
			xml_error(rt, "Light angle value invalid (should be positive).");
	}
}

static void		get_light(t_rt *rt, t_light_lst **light)
{
	t_xml_object	*obj;
	int				nb;

	obj = rt->xml->obj_list;
	obj->props = obj->head_props;
	nb = obj->nb_props;
	while (nb--)
	{
		if (ft_strequ(obj->props->key, "position"))
			(*light)->org = xml_vector(rt, obj->props->key, obj->props->value);
		else if (ft_strequ(obj->props->key, "intensity"))
			(*light)->intensity = xml_float_or_percentage(rt, obj->props->key,
obj->props->value);
		else if (ft_strequ(obj->props->key, "color"))
			(*light)->color = xml_color(rt, obj->props->value);
		else if (ft_strequ(obj->props->key, "axis") ||
ft_strequ(obj->props->key, "angle"))
			get_flashlight(rt, *light, obj->props->key, obj->props->value);
		obj->props = obj->props->next;
	}
	if ((*light)->type == lt_flashlight && ((*light)->axis_exists == 0 ||
(*light)->angle < 0))
		xml_error(rt, "Make sure u entered both axis and angle values");
}

static void		check_light_props(t_rt *rt)
{
	char *accepted[6];
	char *required[1];

	accepted[0] = "position";
	accepted[1] = "type";
	accepted[2] = "intensity";
	accepted[3] = "color";
	accepted[4] = "axis";
	accepted[5] = "angle";
	required[0] = "position";
	check_rt_props(rt, accepted, required, (t_point){6, 1});
}

void			push_rt_light(t_rt *rt)
{
	t_light_lst	*light;

	check_light_props(rt);
	if (!rt->last_light)
	{
		if (!(rt->light = (t_light_lst *)ft_memalloc(sizeof(t_light_lst))))
			free_garbage(rt);
		garbage_collector(rt, rt->light);
		light = rt->light;
	}
	else
	{
		rt->last_light->next = (t_light_lst *)ft_memalloc(sizeof(t_light_lst));
		if (!rt->last_light->next)
			free_garbage(rt);
		garbage_collector(rt, rt->last_light->next);
		light = rt->last_light->next;
	}
	light->color = (t_color){.r = 255, .g = 255, .b = 255};
	light->intensity = 1;
	light->axis_exists = 0;
	light->angle = -1;
	get_light(rt, &light);
	light->next = NULL;
	rt->last_light = light;
}
