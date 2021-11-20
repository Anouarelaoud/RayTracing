/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:31:46 by mderri            #+#    #+#             */
/*   Updated: 2020/11/13 01:15:33 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				distance_help(t_rt *r, t_obj *s)
{
	if (((r->sol1 < r->sol2 || r->sol2 < MIN) && r->sol1 > MIN) &&
	(r->sol1 < r->dis))
	{
		if (getcolorfromtexture(r, s, r->sol1))
		{
			r->dis = r->sol1;
			return (1);
		}
		else
		{
			if ((r->sol2 > MIN)
			&& (r->sol2 < r->dis) && getcolorfromtexture(r, s, r->sol2))
			{
				r->dis = r->sol2;
				return (1);
			}
		}
	}
	return (0);
}

int				distances_tex(t_rt *r, t_obj *s)
{
	if (((r->sol2 < r->sol1 || r->sol1 < MIN) && r->sol2 > MIN) &&
	(r->sol2 < r->dis))
	{
		if (getcolorfromtexture(r, s, r->sol2))
		{
			r->dis = r->sol2;
			return (1);
		}
		else
		{
			if ((r->sol1 > MIN) && (r->sol1 < r->dis) &&
			getcolorfromtexture(r, s, r->sol1))
			{
				r->dis = r->sol1;
				return (1);
			}
		}
	}
	return (distance_help(r, s));
}

int				distances2(t_rt *r, long double c[5])
{
	long double	s[4];
	int			i;
	int			num;
	long double	min;

	i = -1;
	min = MAX;
	if ((num = ft_solve_quartic(c, s)))
	{
		while (++i < num)
		{
			if (s[i] < min && s[i] > MIN)
				min = s[i];
		}
		if (min < r->dis && min > MIN)
		{
			r->dis = min;
			return (1);
		}
	}
	return (0);
}

int				distances3(t_rt *r, long double c[4])
{
	long double	s[3];
	int			i;
	int			num;
	long double	min;

	i = -1;
	min = MAX;
	if ((num = ft_solve_cubic(c, s)))
	{
		while (++i < num)
		{
			if (s[i] < min && s[i] > MIN)
				min = s[i];
		}
		if (min < r->dis && min > MIN)
		{
			r->dis = min;
			return (1);
		}
	}
	return (0);
}

int				distances4(t_rt *r, long double c[4], t_obj *m)
{
	long double	s[3];
	int			h[3];
	long double	min;
	t_vecteur	p;

	h[2] = 0;
	h[0] = -1;
	min = MAX;
	if ((h[1] = ft_solve_cubic(c, s)))
	{
		while (++h[0] < h[1])
		{
			if (s[h[0]] < min && s[h[0]] > MIN)
			{
				min = s[h[0]];
				r->dis = min;
				p = sum(kv(r->u, r->dis), r->cam.position);
				if (in_moebius(m, p))
					h[2] = 1;
			}
		}
		return (h[2] == 1);
	}
	return (0);
}
