/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_camera_operator.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 06:54:20 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/11 23:04:43 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	get_filter(t_rt *rt, char *value)
{
	if (ft_strequ(value, "sepia"))
		return (filter_sepia);
	else if (ft_strequ(value, "motion blur"))
		return (filter_mb);
	else if (ft_strequ(value, "cartoon"))
		return (filter_cartoon);
	else
		xml_error(rt, "Invalid filter name");
	return (0);
}

static void	check_camera_props(t_rt *rt)
{
	char	*accepted[4];
	char	*required[2];

	accepted[0] = "position";
	accepted[1] = "lookat";
	accepted[2] = "focal_length";
	accepted[3] = "filter";
	required[0] = "position";
	required[1] = "lookat";
	check_rt_props(rt, accepted, required, (t_point){4, 2});
}

void		retrieve_camera_operator(t_rt *rt)
{
	int		nb;

	check_camera_props(rt);
	rt->cam.focal_length = 1;
	rt->xml->obj_list->props = rt->xml->obj_list->head_props;
	nb = rt->xml->obj_list->nb_props;
	while (nb--)
	{
		if (ft_strequ(rt->xml->obj_list->props->key, "position"))
			rt->cam.position =
xml_vector(rt, rt->xml->obj_list->props->key, rt->xml->obj_list->props->value);
		else if (ft_strequ(rt->xml->obj_list->props->key, "lookat"))
			rt->cam.lookat =
xml_vector(rt, rt->xml->obj_list->props->key, rt->xml->obj_list->props->value);
		else if (ft_strequ(rt->xml->obj_list->props->key, "focal_length"))
			rt->cam.focal_length =
xml_float_or_percentage(rt, rt->xml->obj_list->props->key,
rt->xml->obj_list->props->value);
		else if (ft_strequ(rt->xml->obj_list->props->key, "filter"))
			rt->cam.f = get_filter(rt, rt->xml->obj_list->props->value);
		rt->xml->obj_list->props = rt->xml->obj_list->props->next;
	}
}
