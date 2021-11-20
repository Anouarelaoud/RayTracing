/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:48:26 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 16:53:09 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

long double		ft_rand3dto1d(t_vecteur value, t_vecteur dot_dir)
{
	t_vecteur		small_value;
	long double		random;

	small_value = create_v(cos(value.x), cos(value.y), cos(value.z));
	random = dot(small_value, dot_dir);
	random = ft_frac(sin(random));
	return (random);
}

long double		ft_rand1dto1d(long double value, long double mutator)
{
	return (ft_frac(sin(value + mutator) * 143758.5453));
}

t_vecteur		ft_rand1dto3d(long double value)
{
	return (create_v(
	ft_rand1dto1d(value, 3.9812),
	ft_rand1dto1d(value, 7.1536),
	ft_rand1dto1d(value, 5.7241)));
}

t_vecteur		ft_rand3dto3d(t_vecteur value)
{
	return (create_v(
	ft_rand3dto1d(value, create_v(102.989, 708.233, 370.719)),
	ft_rand3dto1d(value, create_v(390.346, 110.135, 830.155)),
	ft_rand3dto1d(value, create_v(730.156, 502.235, 90.151))));
}

long double		rand1dto1d(long double value, long double mutator)
{
	long double random;

	random = ft_frac(sin(value + mutator) * 143758.5453);
	return (random);
}
