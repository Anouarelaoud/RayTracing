/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 04:20:03 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/12 18:19:11 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				isdouble(char *str)
{
	int			i;
	int			flag;

	if (!str || (basic_test(str)) == 0)
		return (0);
	i = 0;
	flag = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		if (str[i] == '.')
		{
			if (i == 0)
				return (0);
			if (flag == 0)
				flag = 1;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void			create_camera(t_rt *r)
{
	t_vecteur	up;

	up = create_v(0.000000001, 1, 0.000000001);
	r->cam.forward = normalise(sub(r->cam.lookat, r->cam.position));
	r->cam.left = normalise(vcross(up, r->cam.forward));
	r->cam.up = normalise(vcross(r->cam.forward, r->cam.left));
	r->cam.frame_height = (long double)r->mlx.h / (long double)r->mlx.w;
	r->cam.frame_width = r->cam.frame_height * (long double)r->mlx.w /
(long double)r->mlx.h;
}

long double		module(t_vecteur v1)
{
	return (sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z));
}

t_vecteur		normalise(t_vecteur v1)
{
	t_vecteur u;

	u.x = v1.x / module(v1);
	u.y = v1.y / module(v1);
	u.z = v1.z / module(v1);
	return (u);
}
