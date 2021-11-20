/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:37:32 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/11 05:56:43 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		put_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

int			rgb(int r, int g, int b)
{
	unsigned char	color[4];

	r = fmin(r, 255);
	g = fmin(g, 255);
	b = fmin(b, 255);
	color[0] = b;
	color[1] = g;
	color[2] = r;
	color[3] = 0;
	return (*((int *)color));
}

t_vecteur	create_v(long double x, long double y, long double z)
{
	t_vecteur		v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

void		free_splited(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

long double	clamp(long double v, long double max, long double min)
{
	if (v < min)
		v = min;
	else if (v > max)
		v = max;
	return (v);
}
