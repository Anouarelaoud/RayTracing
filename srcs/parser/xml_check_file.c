/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_check_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 05:13:22 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 02:07:48 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		check_tag_elements(t_rt *rt, char *line, size_t len)
{
	size_t	index;

	index = 1;
	while (!is_whitespace(line[index]))
	{
		if (!strchr(VALID_CHARACTERS, line[index]))
			xml_error(rt, SYNTAX_ERROR);
		index++;
	}
	if (index > 1)
		check_tag_props(rt, line, index, len);
}

static void		check_tag_format(t_rt *rt, char *line, size_t len)
{
	len = ft_strlen(line);
	if (line[len - 1] == 13)
		len--;
	if (line[0] != '<')
		xml_error(rt, SYNTAX_ERROR);
	else if (line[len - 2] != '/' || line[len - 1] != '>')
		xml_error(rt, SYNTAX_ERROR);
	else
		check_tag_elements(rt, line, len);
}

void			xml_check_object(t_rt *rt, char *line, size_t len)
{
	line = ft_strtrim(line);
	check_tag_format(rt, line, len);
}
