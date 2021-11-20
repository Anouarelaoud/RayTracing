/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:53:37 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 16:55:19 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_repere	set_repere(t_vecteur dir)
{
	t_repere	rep;
	t_vecteur	up;

	up = create_v(0.0, 1.0, 0.0);
	rep.j = dir;
	if (equal(up, rep.j) == 1)
	{
		rep.i = create_v(1.0, 0.0, 0.0);
		rep.k = create_v(0.0, 0.0, 1.0);
	}
	else
	{
		if (equal(up, rep.j) == 2)
		{
			rep.i = create_v(-1.0, 0.0, 0.0);
			rep.k = create_v(0.0, 0.0, 1.0);
		}
		else
		{
			rep.i = vcross(up, rep.j);
			rep.k = vcross(rep.i, rep.j);
		}
	}
	return (rep);
}
