/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 02:23:03 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 02:57:08 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "mlx.h"
# include "libft.h"
# include "rt_data_types.h"
# include "xml.h"
# include "ui_ux.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mac.h"

# define PI 3.1415926535
# define ADV 1.04719755117
# define MAX 1e30
# define MIN 1e-4
# define MAX_FILE_SIZE 200000
# define SPECULAR_POWER 30
# define EQN_EPS 1e-9
# define FILTER_MB_W 9
# define FILTER_MB_H 9
# define HEIGHT 1080
# define WIDTH 1920
# define FILTER_C_W 5
# define FILTER_C_H 5
# define FILTERSIZE 25

typedef enum	e_types
{
	tworld, tscreen, tlight, tcamera,
	tplane, tsphere, tcylinder, tcone, ttorus, tparaboloid, tellipsoid,
	thyperboloid, tcubet, tmoebius, tdingdong, tgoursat, tteardrop, tcube, tdisk
}				t_types;

typedef enum	e_light_types
{
	lt_default, lt_directional, lt_parallel, lt_flashlight
}				t_light_types;

typedef enum	e_slice
{
	slice_none, slice_i, slice_j, slice_k
}				t_slice;

typedef enum	e_color_types
{
	c_default, c_texture
}				t_color_types;

typedef enum	e_noise_types
{
	n_none, n_voronoi, n_perlin, n_damier
}				t_noise_types;

typedef enum	e_filter_types
{
	filter_none, filter_mb, filter_sepia, filter_cartoon
}				t_filter_types;

typedef struct	s_data
{
	void	*img_ptr;
	int		bpp;
	int		s_l;
	int		endian;
	int		*pic_str;
}				t_data;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	int		h;
	int		w;
	t_data	d;
}				t_mlx;

typedef	struct	s_rayon
{
	t_vecteur	org;
	t_vecteur	direct;
}				t_rayon;

typedef struct	s_texture
{
	void			*img;
	int				*buf;
	char			*path;
	int				w;
	int				h;
	long double		um;
	long double		vm;
	int				hi;
	int				coup;
	long double		x_offset;
	long double		y_offset;
}				t_texture;

typedef struct	s_color
{
	int			type;
	t_texture	tex;
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_light_lst
{
	struct s_light_lst	*next;
	int					type;
	int					axis_exists;
	t_vecteur			org;
	t_vecteur			axis;
	long double			intensity;
	long double			angle;
	t_color				color;
}				t_light_lst;

typedef struct	s_camera
{
	t_vecteur	lookat;
	t_vecteur	position;
	int			f;
	t_vecteur	up;
	t_vecteur	forward;
	t_vecteur	left;
	long double	focal_length;
	long double	frame_width;
	long double	frame_height;
}				t_camera;

typedef	struct	s_obj
{
	int				type;
	t_color			color;
	int				noise;
	t_vecteur		axe;
	t_vecteur		normal;
	t_vecteur		inter;
	t_vecteur		pos;
	t_vecteur		rot;
	t_vecteur		tr;
	long double		k;
	long double		l;
	t_repere		repere;
	int				sliced;
	long double		limit;
	long double		limitx;
	long double		limitz;
	struct s_obj	*parent;
	t_texture		*txt;
	int				t2;
	struct s_obj	*compos;
	struct s_obj	*head_compos;
	struct s_obj	*next;
}				t_obj;

typedef	struct	s_coef
{
	long double m;
	long double n;
	long double o;
	long double p;
	long double q;
}				t_coef;

typedef struct	s_quartic
{
	long double		a;
	long double		b;
	long double		c;
	long double		d;
	long double		z;
	long double		u;
	long double		v;
	long double		sub;
	long double		sq_a;
	long double		p;
	long double		q;
	long double		r;
}				t_quartic;

typedef struct	s_cubic
{
	long double		a;
	long double		b;
	long double		c;
	long double		d;
	long double		sq_a;
	long double		p;
	long double		q;
	long double		cb_p;
}				t_cubic;

typedef struct	s_garbage
{
	void				*ptr;
	struct s_garbage	*next;
}				t_garbage;

typedef struct	s_rt
{
	t_mlx			mlx;
	t_obj			*obj_list;
	t_obj			*obj;
	t_obj			*head;
	t_obj			*last_obj;
	t_obj			*selected;
	t_color			selected_color;
	t_light_lst		*light;
	t_light_lst		*head_light;
	t_light_lst		*last_light;
	t_rayon			ray;
	t_vecteur		v1;
	t_vecteur		v2;
	t_camera		cam;
	long double		move_factor;
	t_vecteur		u;
	long double		amb;
	long double		res;
	t_color			ambient;
	t_color			diff;
	t_color			spec;
	t_color			color;
	char			*name;
	long double		delta;
	long double		sol1;
	long double		sol2;
	long double		dis;
	t_xml_helper	*xml;
	t_ui			ui;
	t_vecteur		*ran;
	int				hash[255];
	t_garbage		*garbage;
}				t_rt;

typedef struct	s_loop
{
	int			i;
	int			j;
	int			k;
}				t_loop;

typedef struct	s_cell
{
	long double	mindisttocell;
	t_vecteur	base;
	t_vecteur	toclosest;
	t_vecteur	closest;
	t_vecteur	cellposition;
	long double	edgedistance;
}				t_cell;

int				cast_object(t_rt *r);
int				cast_shadow(t_rt *r);
int				distances(t_rt *r);
int				distances_tex(t_rt *r, t_obj *s);
long double		intersection_p(t_rt *r, t_obj *p);
int				intersection_s(t_rt *r, t_obj *s);
int				intersection_c(t_rt *r, t_obj *c);
int				intersection_co(t_rt *r, t_obj *co);
void			get_normal(t_rt *r, t_obj *obj);
int				rat_trace_sphere(t_rt *r, t_obj *obj);
int				rat_trace_plane(t_rt *r, t_obj *obj);
int				rat_trace_cylinder(t_rt *r, t_obj *obj);
int				rat_trace_cone(t_rt *r, t_obj *obj);
void			make_ray(t_rt *r);
void			raytracer(t_rt *r);
void			lighting(t_rt *r);
t_vecteur		sum(t_vecteur v1, t_vecteur v2);
t_vecteur		sub(t_vecteur v1, t_vecteur v2);
t_vecteur		kv(t_vecteur v1, long double k);
long double		dot(t_vecteur v1, t_vecteur v2);
t_vecteur		vcross(t_vecteur v1, t_vecteur v2);
long double		module(t_vecteur v1);
t_vecteur		normalise(t_vecteur v1);
void			free_all(t_rt *r);
int				ft_close(t_rt *r);
int				key_press_handle(int keycode, t_rt *r);
int				mouse_handle(int keycode, int x, int y, t_rt *r);
int				mouse_move(int x, int y, void *param);
void			put_error(char *str);
int				rgb(int r, int g, int b);
t_vecteur		create_v(long double x, long double y, long double z);
void			free_splited(char **tab);
int				isdouble(char *str);
void			create_camera(t_rt *r);
t_color			c(short red, short green, short blue);
void			reset_image(t_rt *rt, t_data *data);
void			final_color(t_rt *r);
void			ambient(t_rt *r, t_color news);
void			diffuse(t_rt *r, long double d, t_light_lst *lst, t_color news);
void			specular(t_rt *r, long double d, t_vecteur dir, t_light_lst *l);
long double		deg_to_rad(long double angle);
t_vecteur		translation(t_vecteur old_pos, t_vecteur tr);
t_vecteur		rotation(t_vecteur axe, t_vecteur rot);
int				basic_test(char *str);
int				distances2(t_rt *r, long double c[5]);
int				distances3(t_rt *r, long double c[4]);
int				intersection_t(t_rt *r, t_obj *t);
int				ft_solve_quartic(long double w[5], long double s[4]);
int				ft_solve_quadric(long double w[3], long double s[2]);
int				ft_solve_cubic(long double w[4], long double s[3]);
int				is_zero(long double delta);
long double		racine_cubique(long double delta);
int				rat_trace_torus(t_rt *r, t_obj *obj);
int				shadow_t(t_rt *r, t_obj *obj);
int				intersection_pb(t_rt *r, t_obj *p);
int				rat_trace_paraboloid(t_rt *r, t_obj *obj);
int				shadow_pb(t_rt *r, t_obj *obj);
void			paraboloid_normal(t_rt *r, t_obj *obj);
int				intersection_ell(t_rt *r, t_obj *ell);
int				rat_trace_ellipsoid(t_rt *r, t_obj *obj);
void			ellipsoid_normal(t_rt *r, t_obj *obj);
int				shadow_ell(t_rt *r, t_obj *obj);
int				intersection_hp(t_rt *r, t_obj *hp);
int				rat_trace_hyperboloid(t_rt *r, t_obj *obj);
void			hyperboloid_normal(t_rt *r, t_obj *obj);
int				intersection_cubet(t_rt *r, t_obj *ct);
int				rat_trace_cubet(t_rt *r, t_obj *obj);
void			cubet_normal(t_rt *r, t_obj *obj);
int				shadow_cubet(t_rt *r, t_obj *obj);
int				intersection_moebius(t_rt *r, t_obj *m);
int				rat_trace_moebius(t_rt *r, t_obj *obj);
void			moebius_normal(t_rt *r, t_obj *obj);
int				shadow_moebius(t_rt *r, t_obj *obj);
int				intersection_dingdong(t_rt *r, t_obj *d);
int				rat_trace_dingdong(t_rt *r, t_obj *obj);
void			dingdong_normal(t_rt *r, t_obj *obj);
int				shadow_dingdong(t_rt *r, t_obj *obj);
int				intersection_goursat(t_rt *r, t_obj *g);
int				rat_trace_goursat(t_rt *r, t_obj *obj);
void			goursat_normal(t_rt *r, t_obj *obj);
int				shadow_goursat(t_rt *r, t_obj *obj);
int				intersection_teardrop(t_rt *r, t_obj *td);
int				rat_trace_teardrop(t_rt *r, t_obj *obj);
void			teardrop_normal(t_rt *r, t_obj *obj);
int				shadow_teardrop(t_rt *r, t_obj *obj);
int				shadow_s(t_rt *r, t_obj *obj);
int				shadow_p(t_rt *r, t_obj *obj);
int				shadow_co(t_rt *r, t_obj *obj);
int				shadow_c(t_rt *r, t_obj *obj);
int				shadow_p(t_rt *r, t_obj *obj);
int				shadow_hp(t_rt *r, t_obj *obj);
int				shadow_t(t_rt *r, t_obj *obj);
int				distances4(t_rt *r, long double c[4], t_obj *m);
int				in_moebius(t_obj *m, t_vecteur p);
int				obj_lst_size(t_rt *rt);
void			xml_error(t_rt *rt, char *message);
int				find_in_tab(char *name, char **tab, int size);
int				is_whitespace(char c);
size_t			skip_whitespaces(char *str, size_t index);
int				xml_int(t_rt *rt, char *prop, char *input);
t_color			xml_color(t_rt *rt, char *input);
t_vecteur		xml_vector(t_rt *rt, char *prop, char *input);
long double		xml_float_or_percentage(t_rt *rt, char *prop, char *input);
void			xml_check_object(t_rt *rt, char *line, size_t len);
char			**custom_split(t_rt *rt, char *line, size_t index);
void			xml_stock_object(t_rt *rt, t_xml_helper *xml, char *line);
void			retrieve_world_operator(t_rt *rt);
void			retrieve_screen_operator(t_rt *rt);
void			retrieve_camera_operator(t_rt *rt);
void			check_plane_props(t_rt *rt);
void			check_sphere_props(t_rt *rt);
void			check_cylinder_props(t_rt *rt);
void			check_cone_props(t_rt *rt);
void			check_torus_props(t_rt *rt);
void			check_paraboloid_props(t_rt *rt);
void			check_ellipsoid_props(t_rt *rt);
void			check_cubet_props(t_rt *rt);
void			check_cube_props(t_rt *rt);
void			check_moebius_props(t_rt *rt);
void			get_standard_props(t_rt *rt, char *key, char *val, t_obj **obj);
void			get_plane(t_rt *rt, t_obj **obj);
void			get_sphere(t_rt *rt, t_obj **obj);
void			get_cylinder(t_rt *rt, t_obj **obj);
void			get_cone(t_rt *rt, t_obj **obj);
void			get_torus(t_rt *rt, t_obj **obj);
void			get_paraboloid(t_rt *rt, t_obj **obj);
void			get_ellipsoid(t_rt *rt, t_obj **obj);
void			get_cubet(t_rt *rt, t_obj **obj);
void			get_moebius(t_rt *rt, t_obj **obj);
void			get_cube(t_rt *rt, t_obj **obj);
void			push_rt_object(t_rt *rt, int type);
void			push_rt_light(t_rt *rt);
void			check_rt_props(t_rt *rt, char **a, char **r, t_point s);
void			xml_parse(char *file, t_rt *rt);
void			print_xml_data(t_xml_helper *xml);
void			filtre(t_rt *rt);
void			ft_filter_mb(t_rt *rt);
void			sepia_filtre(t_rt *rt);
t_vecteur		int_rgb(int c);
int				rgb_int(int r, int g, int b);
int				r(int c);
int				g(int c);
int				b(int c);
long double		clamp(long double v, long double max, long double min);
int				equal(t_vecteur vect1, t_vecteur vect2);
void			add_compos(t_rt *rt, t_obj *obj);
void			project(t_vecteur *p, t_vecteur rot);
t_repere		set_repere(t_vecteur dir);
int				slice(t_obj *obj, t_vecteur p);
int				getcolorfromtexture(t_rt *rt, t_obj *obj, long double t);
int				disk_intersection(t_rt *rt, t_obj *plane);
int				rat_trace_disk(t_rt *r, t_obj *obj);
int				getanglecone(t_obj *cone_temp, t_vecteur p);
int				getanglecylinder(t_obj *plane, t_vecteur p);
int				getangleplan(t_obj *plane_temp, t_vecteur p);
int				getanglesphere(t_obj *sphere_temp, t_vecteur p);
int				load_texture(t_rt *r, t_obj *obj, char *path);
t_color			perlin(t_rt *rt, t_vecteur v, t_obj *obj);
t_vecteur		rand1dto3d(long double value);
long double		ft_rand3dto1d(t_vecteur value, t_vecteur dot_dir);
long double		ft_rand1dto1d(long double value, long double mutator);
t_vecteur		ft_rand1dto3d(long double value);
long double		ft_frac(long double value);
t_color			voronoi_noise(t_vecteur p);
t_vecteur		ft_rand3dto3d(t_vecteur value);
t_color			get_color(t_rt *rt);
void			cartoon_filter(t_rt *rt, int *data);
t_color			checkerboard(t_obj *obj, t_vecteur p);
void			garbage_collector(t_rt *rt, void *ptr);
void			free_garbage(t_rt *rt);
void			texture(t_rt *rt);
void			update_selection(t_rt *r);
void			update_ui_element(t_rt *rt, t_ui_element **e, char *path);
void			update_ui(t_rt *rt);
void			ui(t_rt *rt);
void			init_ui_element(t_rt *rt, t_ui_element **e, t_coor c, char *p);
void			splash_screen(t_rt *rt);
void			update_progressbar(t_rt *rt, double percent);
void			select_object(t_rt *rt, int x, int y);
void			hover(t_rt *rt, int x, int y);
void			add_object_event(t_rt *r, int x, int y);
void			noise_change_event(t_rt *r, int x, int y);
void			color_change_event(t_rt *r, int x, int y);
void			close_button_event(t_rt *rt, int x, int y);
void			print_objs(t_obj *lst);
void			hover_add_sphere(t_rt *rt, int x, int y);
void			hover_add_cylinder(t_rt *rt, int x, int y);
void			hover_add_cone(t_rt *rt, int x, int y);
void			hover_add_plane(t_rt *rt, int x, int y);
void			hover_none(t_rt *rt, int x, int y);
void			put_images(t_rt *rt);
long double		rad_to_deg(long double angle);
void			init_texture(t_texture *txt);
void			project_obj(t_obj **obj, int type);
void			*allocate(t_rt *rt, size_t size);
void			init_obj_list(t_obj **obj, t_rt *rt);
void			apply_noise(t_rt *rt, int noise);
void			get_texture_props(t_rt *rt, t_obj *obj, char *key, char *value);
void			get_normal1(t_rt *r, t_obj *obj);
void			lighting2(t_rt *r, t_light_lst *lst, t_vecteur dir, t_color n);
void			torus_normal(t_rt *r, t_obj *obj);
void			plane_normal(t_obj *obj);
void			get_texture(t_rt *rt, t_obj *obj, char *key, char *value);
void			duplicate(t_rt *rt, t_obj *obj);
void			deselect_object(t_rt *rt, int x, int y);
void			add_plane_compos(t_rt *rt, t_obj *obj);
void			add_cylinder_compos(t_rt *rt, t_obj *obj);
void			add_cone_compos(t_rt *rt, t_obj *obj);
void			add_cube_compos(t_rt *rt, t_obj *obj);
void			add_sphere_compos(t_rt *rt, t_obj *obj);
void			dup_compos(t_obj *obj, t_obj *c, long double x, long double r);
void			check_tag_props(t_rt *rt, char *line, size_t index, size_t len);
void			get_property_value(t_rt *rt, char *string, t_xml_props **prop);
void			cast_object_help(t_rt *r, t_obj *compos);

#endif
