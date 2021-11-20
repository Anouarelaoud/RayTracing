/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rt_props.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 06:30:36 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/11 06:31:16 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	find_in_props(char *key, t_xml_object *obj)
{
	int i;
	int nb;

	i = 0;
	obj->props = obj->head_props;
	nb = obj->nb_props;
	while (nb--)
	{
		if (ft_strequ(obj->props->key, key))
			return (i);
		i++;
		obj->props = obj->props-> next;
	}
	return (-1);
}

void		check_rt_props(t_rt *rt, char **acc, char **req, t_point sze)
{
	int	i;
	int	nb;

	i = 0;
	while (i < sze.y)
	{
		if (find_in_props(req[i], rt->xml->obj_list) < 0)
			xml_error(rt, SYNTAX_ERROR);
		i++;
	}
	rt->xml->obj_list->props = rt->xml->obj_list->head_props;
	nb = rt->xml->obj_list->nb_props;
	while (nb--)
	{
		if (find_in_tab(rt->xml->obj_list->props->key, acc, sze.x) < 0)
			xml_error(rt, SYNTAX_ERROR);
		rt->xml->obj_list->props = rt->xml->obj_list->props->next;
	}
}
