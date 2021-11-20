/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:57:19 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/12 17:00:13 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			r(int c)
{
	return ((c >> 16) & 0xFF);
}

int			g(int c)
{
	return ((c >> 8) & 0xFF);
}

int			b(int c)
{
	return (c & 0xFF);
}

int			rgb_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

t_vecteur	int_rgb(int c)
{
	return (create_v(r(c), g(c), b(c)));
}
