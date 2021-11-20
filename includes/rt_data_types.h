/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 02:49:13 by aait-el-          #+#    #+#             */
/*   Updated: 2020/11/11 02:50:10 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_TYPES_H
# define RT_DATA_TYPES_H

typedef struct		s_vecteur
{
	long double	x;
	long double	y;
	long double	z;
}					t_vecteur;

typedef struct		s_point
{
	int x;
	int y;
}					t_point;

typedef struct		s_repere
{
	t_vecteur		i;
	t_vecteur		j;
	t_vecteur		k;
}					t_repere;

typedef struct		s_coor
{
	int		x;
	int		y;
	int		w;
	int		h;
}					t_coor;

#endif
