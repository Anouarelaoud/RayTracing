/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 06:37:56 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 02:32:11 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	get_sliced(t_rt *rt, char *value)
{
	if (ft_strequ(value, "yes"))
		return (1);
	else if (ft_strequ(value, "no"))
		return (0);
	else
		xml_error(rt, "Invalid slice value");
	return (-1);
}

void		init_texture(t_texture *txt)
{
	txt->hi = 1.0;
	txt->coup = 0;
	txt->x_offset = 0;
	txt->y_offset = 0;
}

static int	get_noise_type(t_rt *rt, t_obj *obj, char *value)
{
	if (obj->color.type == c_texture)
		return (n_none);
	if (ft_strequ(value, "voronoi"))
		return (n_voronoi);
	if (ft_strequ(value, "perlin"))
		return (n_perlin);
	if (ft_strequ(value, "damier"))
	{
		if (!(obj->txt = (t_texture *)ft_memalloc(sizeof(t_texture))))
			free_garbage(rt);
		garbage_collector(rt, obj->txt);
		init_texture(obj->txt);
		return (n_damier);
	}
	else
		xml_error(rt, "Unknown noise name.");
	return (-1);
}

void		get_standard_props(t_rt *rt, char *key, char *value, t_obj **obj)
{
	if (ft_strequ(key, "position"))
		(*obj)->pos = xml_vector(rt, key, value);
	else if (ft_strequ(key, "color"))
		(*obj)->color = xml_color(rt, value);
	else if (ft_strequ(key, "translation"))
		(*obj)->tr = xml_vector(rt, key, value);
	else if (ft_strequ(key, "rotation"))
		(*obj)->rot = xml_vector(rt, key, value);
	else if (ft_strequ(key, "noise"))
		(*obj)->noise = get_noise_type(rt, *obj, value);
	else if (ft_strequ(key, "sliced"))
		(*obj)->sliced = get_sliced(rt, value);
}

void		get_sphere(t_rt *rt, t_obj **obj)
{
	t_xml_object	*xobj;
	int				nb;

	xobj = rt->xml->obj_list;
	xobj->props = xobj->head_props;
	nb = xobj->nb_props;
	(*obj)->color = (t_color){.type = c_default, .r = 255, .g = 0, .b = 0};
	while (nb--)
	{
		get_standard_props(rt, xobj->props->key, xobj->props->value, obj);
		if (ft_strequ(xobj->props->key, "rayon"))
			(*obj)->k = xml_float_or_percentage(rt, xobj->props->key,
xobj->props->value);
		else if (ft_strequ(xobj->props->key, "limit"))
			(*obj)->limit =
xml_float_or_percentage(rt, xobj->props->key, xobj->props->value);
		else if (ft_strequ(xobj->props->key, "axe"))
			(*obj)->axe = xml_vector(rt, xobj->props->key, xobj->props->value);
		else if (ft_strequ(xobj->props->key, "rotation"))
			(*obj)->rot = xml_vector(rt, xobj->props->key, xobj->props->value);
		get_texture_props(rt, *obj, xobj->props->key, xobj->props->value);
		xobj->props = xobj->props->next;
	}
	if ((*obj)->sliced && (*obj)->color.type == c_texture)
		xml_error(rt, "Cannot apply texture on sliced objects.");
}
