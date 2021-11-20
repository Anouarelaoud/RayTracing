/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 02:11:01 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 02:20:05 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		is_hexa(char *input)
{
	int	i;
	int	c;

	i = 1;
	if (ft_strlen(input) != 7 || input[0] != '#')
		return (0);
	while (input[i])
	{
		c = ft_tolower(input[i]);
		if (!((c > 47 && c < 58) || (c > 96 && c < 103)))
			return (0);
		i++;
	}
	return (1);
}

static int		is_rgb(char *input)
{
	char	**tab;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(input);
	if (input[0] != 'r' || input[1] != 'g' || input[2] != 'b' ||
input[3] != '(' || input[len - 1] != ')')
		return (0);
	tab = ft_strsplit(ft_strsub(input, 4, len - 5), ',');
	if (!tab[2] || tab[3])
		return (0);
	while (i < 3)
	{
		if (!isdouble(ft_strtrim(tab[i])))
			return (0);
		i++;
	}
	free_splited(tab);
	return (1);
}

static t_color	get_hexa(char *input)
{
	char	red[3];
	char	green[3];
	char	blue[3];

	red[0] = input[1];
	red[1] = input[2];
	red[2] = '\0';
	green[0] = input[3];
	green[1] = input[4];
	green[2] = '\0';
	blue[0] = input[5];
	blue[1] = input[6];
	blue[2] = '\0';
	return ((t_color) {
.type = c_default,
.r = ft_atoi_base(red, 16),
.g = ft_atoi_base(green, 16),
.b = ft_atoi_base(blue, 16)
});
}

static t_color	get_rgb(char *input)
{
	char	**tab;
	size_t	len;
	t_color	ret;

	len = ft_strlen(input);
	tab = ft_strsplit(ft_strsub(input, 4, len - 5), ',');
	ret = (t_color){
.type = c_default,
.r = ft_atoi(ft_strtrim(tab[0])),
.g = ft_atoi(ft_strtrim(tab[1])),
.b = ft_atoi(ft_strtrim(tab[2]))
	};
	free_splited(tab);
	return (ret);
}

t_color			xml_color(t_rt *rt, char *input)
{
	if (is_hexa(input))
		return (get_hexa(input));
	else if (is_rgb(input))
		return (get_rgb(input));
	else
		xml_error(rt, "Expected an rgb or hexadecimal color value.\
\n\033[0mexample: <sphere color=\"rgb(255, 255, 255)\" .... />\
\nor: <sphere color=\"#FFFFFF\" .... />");
	return ((t_color){.r = 0, .g = 0, .b = 0});
}
