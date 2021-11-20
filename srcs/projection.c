/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:47:45 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 18:58:55 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	rotate_x(long double *y, long double *z, long double alpha)
{
	long double previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

static void	rotate_y(long double *x, long double *z, long double beta)
{
	long double previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

static void	rotate_z(long double *x, long double *y, long double gamma)
{
	long double previous_x;
	long double previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

void		project(t_vecteur *p, t_vecteur rot)
{
	rotate_x(&(*p).y, &(*p).z, rot.x);
	rotate_y(&(*p).x, &(*p).z, rot.y);
	rotate_z(&(*p).x, &(*p).y, rot.z);
}

t_vecteur	rand1dto3d(long double value)
{
	return (create_v(ft_rand1dto1d(value, 3.9812),
	ft_rand1dto1d(value, 7.1536), ft_rand1dto1d(value, 5.7241)));
}
