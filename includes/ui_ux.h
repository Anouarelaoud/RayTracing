/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_ux.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:08:49 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/12 01:18:16 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_UX_H
# define UI_UX_H

# define RENDER_W 1800
# define RENDER_H 900
# define RENDER_X 126
# define RENDER_Y 190
# define PB_W RENDER_W
# define PB_H 3
# define PB_X 126
# define PB_Y 1077
# define WHITE 0xFFFFFF
# define TOTAL_PIXELS 1620000

typedef struct	s_dataa
{
	int		bpp;
	int		s_l;
	int		endian;
	int		*pic_str;
}				t_dataa;

typedef struct	s_ui_element
{
	void	*ptr;
	t_dataa	d;
	int		w;
	int		h;
	int		x;
	int		y;
	int		hovered;
}				t_ui_element;

typedef struct	s_ui
{
	t_ui_element	*toolbar_top;
	t_ui_element	*toolbar_left;
	t_ui_element	*tab_bar;
	t_ui_element	*tab;
	t_ui_element	*logo_small;
	t_ui_element	*s_logo_large;
	t_ui_element	*add_sphere;
	t_ui_element	*add_cylinder;
	t_ui_element	*add_cone;
	t_ui_element	*add_plane;
	t_ui_element	*selected;
	t_ui_element	*none;
	t_ui_element	*texture1;
	t_ui_element	*texture2;
	t_ui_element	*texture3;
	t_ui_element	*noise_voronoi;
	t_ui_element	*noise_perlin;
	t_ui_element	*noise_damier;
	t_ui_element	*aa_half;
	t_ui_element	*aa_one;
	t_ui_element	*aa_two;
	t_ui_element	*close;
	t_ui_element	*remove;
	t_ui_element	*pb;
	t_ui_element	*color_wheel;
	long double		current_progress;
	long double		last_progress;
	int				activate_pb;
}				t_ui;

#endif
