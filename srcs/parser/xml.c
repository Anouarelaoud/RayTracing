/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:45:22 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/13 02:48:31 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		retrieve_obj_type(t_rt *rt, char *name)
{
	int		type;
	char	*tab[18];

	tab[0] = "world";
	tab[1] = "screen";
	tab[2] = "light";
	tab[3] = "camera";
	tab[4] = "plane";
	tab[5] = "sphere";
	tab[6] = "cylinder";
	tab[7] = "cone";
	tab[8] = "torus";
	tab[9] = "paraboloid";
	tab[10] = "ellipsoid";
	tab[11] = "hyperboloid";
	tab[12] = "cubet";
	tab[13] = "moebius";
	tab[14] = "dingdong";
	tab[15] = "goursat";
	tab[16] = "teardrop";
	tab[17] = "cube";
	if ((type = find_in_tab(name, tab, 18)) < 0)
		xml_error(rt, ft_strjoin("No such an RT object name: ", name));
	return (type);
}

static void		xml_to_rt(t_rt *rt)
{
	int	type;

	rt->xml->obj_list = rt->xml->head_obj;
	while (rt->xml->obj_list)
	{
		type = retrieve_obj_type(rt, rt->xml->obj_list->name);
		if (type == tworld)
			retrieve_world_operator(rt);
		else if (type == tscreen)
			retrieve_screen_operator(rt);
		else if (type == tlight)
			push_rt_light(rt);
		else if (type == tcamera)
			retrieve_camera_operator(rt);
		else
			push_rt_object(rt, type);
		rt->xml->obj_list = rt->xml->obj_list->next;
	}
}

void			norm_parse(t_rt *rt, int *fd, char *file)
{
	rt->xml->obj_list = (t_xml_object *)ft_memalloc(sizeof(t_xml_object));
	if (!rt->xml->obj_list)
		free_garbage(rt);
	garbage_collector(rt, rt->xml->obj_list);
	rt->xml->nb_obj = 0;
	rt->xml->head_obj = rt->xml->obj_list;
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		xml_error(rt, "Cannot open this file.");
}

void			norm_parse2(t_rt *rt, size_t *len, char *line)
{
	*len = ft_strlen(line);
	line = ft_strtrim(line);
	xml_check_object(rt, line, *len);
	rt->xml->nb_obj++;
	xml_stock_object(rt, rt->xml, line);
	rt->xml->obj_list->next =
(t_xml_object *)ft_memalloc(sizeof(t_xml_object));
	if (!rt->xml->obj_list->next)
		free_garbage(rt);
	garbage_collector(rt, rt->xml->obj_list->next);
	rt->xml->tmp_obj = rt->xml->obj_list;
	rt->xml->obj_list = rt->xml->obj_list->next;
}

void			xml_parse(char *file, t_rt *rt)
{
	char			*line;
	size_t			len;
	int				fd[2];
	int				flag;

	norm_parse(rt, &fd[0], file);
	flag = 0;
	while ((fd[1] = get_next_line(fd[0], &line)))
	{
		flag = 1;
		if (fd[1] < 0)
		{
			close(fd[0]);
			xml_error(rt, "Read error.");
		}
		norm_parse2(rt, &len, line);
	}
	if (!fd[1] && !flag)
	{
		close(fd[0]);
		xml_error(rt, "Empty file");
	}
	rt->xml->tmp_obj->next = NULL;
	xml_to_rt(rt);
	close(fd[0]);
}
