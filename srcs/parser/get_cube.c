/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 23:07:53 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/12 18:28:57 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_cube(t_rt *rt, t_obj **obj)
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
		if (ft_strequ(xobj->props->key, "k"))
			(*obj)->k = xml_float_or_percentage(rt, xobj->props->key,
xobj->props->value);
		else if (ft_strequ(xobj->props->key, "axe"))
			(*obj)->axe = xml_vector(rt, xobj->props->value,
xobj->props->value);
		xobj->props = xobj->props->next;
	}
}
