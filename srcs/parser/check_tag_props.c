/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tag_props.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 02:08:08 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 02:19:35 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		key_val1(int *key, int *value, size_t *index, size_t indexx)
{
	*key = 1;
	*value = 0;
	*index = indexx;
}

static void		key_val2(int *key, int *value, size_t *index, size_t indexx)
{
	*key = 0;
	*value = 1;
	*index = indexx;
}

static void		check_tag_props_1(t_rt *rt, char *line, size_t index)
{
	if (!strchr(VALID_CHARACTERS, line[index]))
		xml_error(rt, SYNTAX_ERROR);
}

static void		check_tag_props_2(t_rt *rt, char *line, size_t *index)
{
	if (line[*index] != '"')
		xml_error(rt, SYNTAX_ERROR);
	(*index)++;
	while (line[*index] && line[*index] != '"')
		(*index)++;
	if (line[*index] != '"')
		xml_error(rt, SYNTAX_ERROR);
}

void			check_tag_props(t_rt *rt, char *line, size_t index, size_t len)
{
	int key;
	int value;

	key_val1(&key, &value, &index, skip_whitespaces(line, index));
	while (index < len - 2)
	{
		if (line[index] == '=' && key)
			key_val2(&key, &value, &index, index + 1);
		if (key)
			check_tag_props_1(rt, line, index);
		if (value)
		{
			check_tag_props_2(rt, line, &index);
			if (is_whitespace(line[index + 1]))
			{
				key_val1(&key, &value, &index, skip_whitespaces(line,
index + 1));
				continue ;
			}
			else if (line[index + 1] != '/' && line[index + 2] != '>')
				xml_error(rt, SYNTAX_ERROR);
		}
		index++;
	}
}
