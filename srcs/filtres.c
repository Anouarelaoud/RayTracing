/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:50:25 by erahimi           #+#    #+#             */
/*   Updated: 2020/11/12 23:02:07 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	filtre(t_rt *rt)
{
	if (rt->cam.f == filter_mb)
		ft_filter_mb(rt);
	if (rt->cam.f == filter_sepia)
		sepia_filtre(rt);
	if (rt->cam.f == filter_cartoon)
		cartoon_filter(rt, rt->mlx.d.pic_str);
}
