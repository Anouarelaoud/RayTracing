/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 02:19:01 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 02:19:17 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int			is_vector(char *input)
{
	size_t	len;
	char	**tab;
	int		i;

	len = ft_strlen(input);
	i = 0;
	if (input[0] != '(' || input[len - 1] != ')')
		return (0);
	tab = ft_strsplit(ft_strsub(input, 1, len - 2), ',');
	if (tab[3] || !tab[2])
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

static t_vecteur	get_vector(char *input)
{
	t_vecteur	vect;
	char		**tab;

	tab = ft_strsplit(ft_strsub(input, 1, ft_strlen(input) - 2), ',');
	vect = (t_vecteur){
ft_atof(ft_strtrim(tab[0])),
ft_atof(ft_strtrim(tab[1])),
ft_atof(ft_strtrim(tab[2]))
	};
	free_splited(tab);
	return (vect);
}

t_vecteur			xml_vector(t_rt *rt, char *prop, char *input)
{
	if (!is_vector(input))
		xml_error(rt, ft_strjoin("Expected a vector value \
\"ex: <sphere position=\"(0, 0, 0)\" .... />\" in the following \
property: ", prop));
	return (get_vector(input));
}
