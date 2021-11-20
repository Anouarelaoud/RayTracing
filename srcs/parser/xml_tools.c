/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 05:15:47 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 02:18:38 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	xml_error(t_rt *rt, char *message)
{
	ft_putstr("\033[1;31m");
	ft_putendl(message);
	ft_putstr("\033[0m\n\n");
	free_garbage(rt);
}

int		find_in_tab(char *name, char **tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (ft_strequ(name, tab[i]))
			return (i);
		i++;
	}
	return (-1);
}

int		is_whitespace(char c)
{
	return (c == '\n' || c == '\t' || c == ' ' || c == '\v' ||
	c == '\f' || c == '\r');
}

size_t	skip_whitespaces(char *str, size_t index)
{
	while (str[index] && strchr(WHITESPACES, str[index]))
		index++;
	return (index);
}

void	get_property_value(t_rt *rt, char *string, t_xml_props **prop)
{
	char	**tab;
	size_t	len;

	tab = ft_strsplit(string, '=');
	if (!tab[1])
		xml_error(rt, SYNTAX_ERROR);
	len = ft_strlen(tab[1]);
	(*prop)->value = ft_strtrim(ft_strsub(tab[1], 1, len - 2));
	free_splited(tab);
}
