/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur_operations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:20:15 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 18:20:37 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			equal(t_vecteur vect1, t_vecteur vect2)
{
	if (vect1.y == vect2.y)
		return (1);
	if (vect1.y == -vect2.y)
		return (2);
	return (0);
}

int			obj_lst_size(t_rt *rt)
{
	int		size;
	t_obj	*obj;

	size = 0;
	obj = rt->head;
	while (obj)
	{
		size++;
		obj = obj->next;
	}
	return (size);
}
