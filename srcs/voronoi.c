/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   voronoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:06:01 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 17:08:28 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vecteur			ft_vfloor(t_vecteur v)
{
	return (create_v(floor(v.x), floor(v.y), floor(v.z)));
}

static void			ft_voronoi_1(t_cell *c, t_vecteur value)
{
	t_cell		tmp;
	t_vecteur	cellposition;
	int			i;
	int			j;
	int			k;

	i = -2;
	while (++i <= 1)
	{
		j = -2;
		while (++j <= 1)
		{
			k = -2;
			while (++k <= 1)
			{
				tmp.base = c->base;
				tmp.closest = sum(c->base, create_v(i, j, k));
				cellposition = sum(tmp.closest, ft_rand3dto3d(tmp.closest));
				tmp.toclosest = sub(cellposition, value);
				tmp.mindisttocell = module(tmp.toclosest);
				if (tmp.mindisttocell < c->mindisttocell)
					*c = tmp;
			}
		}
	}
}

static t_vecteur	ft_voronoi(t_vecteur value)
{
	t_cell			c;
	long double		random;

	c.base = ft_vfloor(value);
	c.mindisttocell = 10;
	ft_voronoi_1(&c, value);
	random = ft_rand3dto1d(c.closest, create_v(12.9898, 78.233, 37.719));
	return (ft_rand1dto3d(random));
}

t_color				voronoi_noise(t_vecteur p)
{
	t_color		dist;
	t_vecteur	result;

	result = kv(ft_voronoi(kv(p, 1.0)), 255.0);
	dist.r = result.x;
	dist.g = result.y;
	dist.b = result.z;
	return (dist);
}
