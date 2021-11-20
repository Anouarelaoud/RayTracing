# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 23:51:03 by mderri            #+#    #+#              #
#    Updated: 2020/11/12 22:12:50 by aait-el-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
INCS = -I ./frameworks/minilibx -I ./includes
CFLAGS1 = -Wextra -Wall -Werror $(INCS)
LIBS = -L ./frameworks/minilibx -lmlx -L ./srcs/libft -lft -L ./frameworks/zlib -lz -framework OpenGL -framework AppKit
NAME = rt

SRC =	 tools.c\
		tools2.c\
		tools3.c\
		sphere.c\
		keyhandle.c\
		keyhandle2.c\
		vecteur_operations.c\
		vecteur_operations2.c\
		cone.c\
		plan.c\
		cylinder.c\
		raytracer.c\
		lighting.c\
		lighting2.c\
		shadow.c\
		get_normals.c\
		transformations.c\
		free_all.c\
		torus.c\
		quartic.c\
		quadric.c\
		cubic.c\
		distance.c\
		elliptic_paraboloid.c\
		ellipsoid.c\
		hyperboloid.c\
		cube_troue.c\
		moebius.c\
		dingdong.c\
		goursat.c\
		tear_drop.c\
		rt.c\
		xml.c\
		xml_tools.c\
		xml_check_file.c\
		xml_custom_split.c\
		xml_stock_data.c\
		check_props_per_object.c\
		check_props_per_object_2.c\
		check_rt_props.c\
		get_sphere.c\
		get_plane.c\
		get_cylinder.c\
		get_cone.c\
		get_torus.c\
		get_paraboloid.c\
		get_ellipsoid.c\
		get_cubet.c\
		get_cube.c\
		get_moebius.c\
		push_rt_light.c\
		push_rt_object.c\
		retrieve_camera_operator.c\
		retrieve_screen_operator.c\
		retrieve_world_operator.c\
		xml_color.c\
		xml_float_or_percentage.c\
		xml_vector.c\
		xml_int.c\
		ui.c\
		ux.c\
		filtres.c\
		mb_filter.c\
		sepia_filtre.c\
		rgb.c\
		projection.c\
		repere.c \
		add_component.c\
		add_component2.c\
		add_component3.c\
		slice.c\
		texture.c\
		disk.c\
		update_ui.c\
		hover1.c\
		hover2.c\
		add_object_event.c\
		load_texture.c\
		voronoi.c\
		perlin.c\
		rand.c\
		get_color.c\
		cartoon.c\
		board.c\
		garbage.c\
		noise_change_event.c\
		progress_bar.c\
		color_change_event.c\
		put_images.c\
		tools4.c\
		get_texture.c\
		get_normals_2.c\
		get_normals_3.c\
		shadow2.c\
		shadow3.c\
		check_tag_props.c

PARSE_SRC = xml.c


OBJ = $(SRC:%.c=objs/%.o)
DIRECTORY = objs

all: $(NAME)

$(NAME): $(DIRECTORY) $(OBJ)
	@make -C srcs/libft
	@make -C frameworks/minilibx
	@make -C frameworks/zlib
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS1) $(LIBS)
	@echo "\033[0;31m ================================================================================"
	@echo "\033[0;31m|>>>>>>>>>>>>>>>>>>>>\033[0;35m{YOUR RT HAS BEEN COMPILED SUCCESSFULLY}\033[0;31m<<<<<<<<<<<<<<<<<<|"
	@echo "\033[0;31m ================================================================================"

$(DIRECTORY):
	mkdir -p objs

objs/%.o: srcs/%.c includes/rt.h includes/rt_data_types.h includes/mac.h includes/ui_ux.h includes/xml.h
	gcc $(CFLAGS1) -c $< -o $@

objs/%.o: srcs/parser/%.c includes/rt.h includes/rt_data_types.h includes/mac.h includes/ui_ux.h includes/xml.h
	gcc $(CFLAGS1) -c $< -o $@

objs/%.o: srcs/ui_ux/%.c includes/rt.h includes/rt_data_types.h includes/mac.h includes/ui_ux.h includes/xml.h
	gcc $(CFLAGS1) -c $< -o $@

clean:
	@rm -rf objs
	@rm -f $(OBJ)
	@make clean -C srcs/libft
	@make clean -C frameworks/minilibx
	@make clean -C frameworks/zlib
	@echo "\033[0;31m ================================================================================"
	@echo "\033[0;31m|>>>>>>>>>>>>>>>>>>>>>\033[0;32m{YOUR RT HAS BEEN CLEANED SUCCESSFULLY}\033[0;31m<<<<<<<<<<<<<<<<<<|"
	@echo "\033[0;31m ================================================================================"

fclean: clean
	@make fclean -C srcs/libft
	@rm -f $(NAME)

re: fclean all
.PHONY: fclean, clean, re, all, rt
