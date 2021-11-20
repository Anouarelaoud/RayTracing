/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 06:31:49 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/12 05:12:54 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	slice_cone(t_rt *rt, t_obj *obj, char *value)
{
	obj->sliced = 1;
	obj->limit = xml_float_or_percentage(rt, "limit", value);
	if (obj->limit < 0)
		xml_error(rt, "Invalid value for limit.");
}

void		get_cone(t_rt *rt, t_obj **obj)
{
	t_xml_object	*xobj;
	int				nb;

	xobj = rt->xml->obj_list;
	xobj->props = xobj->head_props;
	nb = xobj->nb_props;
	(*obj)->color = (t_color){.type = c_default, .r = 0, .g = 0, .b = 255};
	while (nb--)
	{
		get_standard_props(rt, xobj->props->key, xobj->props->value, obj);
		if (ft_strequ(xobj->props->key, "k"))
			(*obj)->k = xml_float_or_percentage(rt, xobj->props->key,
xobj->props->value);
		else if (ft_strequ(xobj->props->key, "axe"))
			(*obj)->axe = xml_vector(rt, xobj->props->value,
xobj->props->value);
		else if (ft_strequ(xobj->props->key, "limit"))
			slice_cone(rt, *obj, xobj->props->value);
		get_texture_props(rt, *obj, xobj->props->key, xobj->props->value);
		xobj->props = xobj->props->next;
	}
	if ((*obj)->sliced && (*obj)->color.type == c_texture)
		xml_error(rt, "Cannot apply texture on sliced objects.");
}
