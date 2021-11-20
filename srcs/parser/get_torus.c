/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_torus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 06:38:32 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/11 06:38:54 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_torus(t_rt *rt, t_obj **obj)
{
	t_xml_object	*xobj;
	int				nb;

	xobj = rt->xml->obj_list;
	xobj->props = xobj->head_props;
	nb = xobj->nb_props;
	(*obj)->color = (t_color){.type = c_default, .r = 255, .g = 0, .b = 255};
	while (nb--)
	{
		get_standard_props(rt, xobj->props->key, xobj->props->value, obj);
		if (ft_strequ(xobj->props->key, "k"))
			(*obj)->k = xml_float_or_percentage(rt, xobj->props->key,
xobj->props->value);
		else if (ft_strequ(xobj->props->key, "l"))
			(*obj)->l =
xml_float_or_percentage(rt, xobj->props->key, xobj->props->value);
		else if (ft_strequ(xobj->props->key, "axe"))
			(*obj)->axe = xml_vector(rt, xobj->props->key, xobj->props->value);
		xobj->props = xobj->props->next;
	}
}
