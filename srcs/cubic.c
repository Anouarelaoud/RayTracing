/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:32:06 by mderri            #+#    #+#             */
/*   Updated: 2020/03/18 13:32:09 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_case_one(long double s[2], long double *q)
{
	int			num;
	long double	u;

	if (is_zero(*q))
	{
		s[0] = 0;
		num = 1;
	}
	else
	{
		u = racine_cubique(-(*q));
		s[0] = 2.0 * u;
		s[1] = -u;
		num = 2;
	}
	return (num);
}

static int	ft_case_two(long double s[3], long double *q, long double *p,
long double *cb_p)
{
	long double	phi;
	long double	t;

	phi = 1.0 / 3.0 * acos(-(*q) / sqrt(-(*cb_p)));
	t = 2.0 * sqrt(-(*p));
	s[0] = t * cos(phi);
	s[1] = -t * cos(phi + M_PI / 3.0);
	s[2] = -t * cos(phi - M_PI / 3.0);
	return (3);
}

static int	ft_case_three(long double s[3], long double *q, long double *d)
{
	long double	sqrt_d;
	long double	u;
	long double	v;

	sqrt_d = sqrt(*d);
	u = racine_cubique(sqrt_d - (*q));
	v = -racine_cubique(sqrt_d + (*q));
	s[0] = u + v;
	return (1);
}

int			ft_solve_cubic(long double w[4], long double s[3])
{
	int			i;
	int			num;
	long double	sub;
	t_cubic		c;

	c.a = w[2] / w[3];
	c.b = w[1] / w[3];
	c.c = w[0] / w[3];
	c.sq_a = c.a * c.a;
	c.p = 1.0 / 3.0 * (-1.0 / 3.0 * c.sq_a + c.b);
	c.q = 1.0 / 2.0 * (2.0 / 27.0 * c.a * c.sq_a - 1.0 / 3.0 * c.a * c.b + c.c);
	c.cb_p = c.p * c.p * c.p;
	c.d = c.q * c.q + c.cb_p;
	if (is_zero(c.d))
		num = ft_case_one(s, &c.q);
	else if (c.d < 0.0f)
		num = ft_case_two(s, &c.q, &c.p, &c.cb_p);
	else
		num = ft_case_three(s, &c.q, &c.d);
	sub = 1.0 / 3.0 * c.a;
	i = -1;
	while (++i < num)
		s[i] -= sub;
	return (num);
}
