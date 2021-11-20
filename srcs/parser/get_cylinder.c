/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 06:34:37 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 00:36:52 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	slice_cylinder(t_rt *rt, t_obj *obj, char *value)
{
	obj->sliced = 1;
	obj->limit = xml_float_or_percentage(rt, "limit", value);
	if (obj->limit < 0)
		xml_error(rt, "Invalid value for limit.");
}

void		get_cylinder(t_rt *rt, t_obj **obj)
{
	t_xml_object	*xobj;
	int				nb;

	xobj = rt->xml->obj_list;
	xobj->props = xobj->head_props;
	nb = xobj->nb_props;
	(*obj)->color = (t_color){.type = c_default, .r = 0, .g = 255, .b = 0};
	while (nb--)
	{
		get_standard_props(rt, xobj->props->key, xobj->props->value, obj);
		if (ft_strequ(xobj->props->key, "rayon"))
			(*obj)->k = xml_float_or_percentage(rt, xobj->props->key,
xobj->props->value);
		else if (ft_strequ(xobj->props->key, "axe"))
			(*obj)->axe = xml_vector(rt, xobj->props->value,
xobj->props->value);
		else if (ft_strequ(xobj->props->key, "limit"))
			slice_cylinder(rt, *obj, xobj->props->value);
		get_texture_props(rt, *obj, xobj->props->key, xobj->props->value);
		xobj->props = xobj->props->next;
	}
	if ((*obj)->sliced && (*obj)->color.type == c_texture)
		xml_error(rt, "Cannot apply texture on sliced objects.");
}
