/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:29:45 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/13 00:29:46 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

long double		ft_frac(long double value)
{
	return (value - floor(value));
}

long double		ft_acc(t_vecteur c[2][2][2], t_vecteur v, long double acc)
{
	int			i;
	int			j;
	int			k;
	t_vecteur	weight;
	t_vecteur	noise;

	noise = create_v(v.x * v.x * (3.0 - 2.0 * v.x), v.y * v.y *
	(3.0 - 2.0 * v.y), v.z * v.z * (3.0 - 2.0 * v.z));
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		{
			k = -1;
			while (++k < 2)
			{
				weight = create_v(v.x - i, v.y - j, v.z - k);
				acc += (i * noise.x + (1 - i) * (1 - noise.x)) *
				(j * noise.y + (1 - j) * (1 - noise.y)) * (k * noise.z +
				(1 - k) * (1 - noise.z)) * dot(c[i][j][k], weight);
			}
		}
	}
	return (acc);
}

long double		noise(t_rt *rt, t_vecteur v)
{
	t_vecteur	c[2][2][2];
	t_vecteur	acc;
	int			i;
	int			j;
	int			k;

	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		{
			k = -1;
			while (++k < 2)
			{
				c[i][j][k] = rt->ran[rt->hash[((int)floor(v.x) + i) &
				255] ^ rt->hash[((int)floor(v.y) + j) &
				255] ^ rt->hash[((int)floor(v.z) + k) & 255]];
			}
		}
	}
	acc = create_v(ft_frac(v.x), ft_frac(v.y), ft_frac(v.z));
	return (ft_acc(c, acc, 0.0));
}

long double		perlin_noise(t_rt *rt, t_vecteur v, int depth)
{
	long double		acc;
	long double		weight;
	int				i;

	acc = 0.0;
	weight = 1.0;
	i = -1;
	while (++i < depth)
	{
		acc += weight * noise(rt, v);
		weight *= 0.5;
		v = kv(v, 2.0);
	}
	return (fabs((double)acc));
}

t_color			perlin(t_rt *rt, t_vecteur v, t_obj *obj)
{
	t_color		dist;
	long double	result;

	result = 9.0 * perlin_noise(rt, v, 2);
	dist.r = (long double)obj->color.r * result;
	dist.g = (long double)obj->color.g * result;
	dist.b = (long double)obj->color.b * result;
	return (dist);
}
