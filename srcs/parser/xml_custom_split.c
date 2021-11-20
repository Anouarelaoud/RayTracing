/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_custom_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 05:23:52 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/13 02:11:43 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		get_custom_words_number(char *line, size_t index)
{
	int		nb;
	int		in_word;

	nb = 0;
	in_word = 0;
	while (line[index + 3])
	{
		if (line[index] == '"')
		{
			index++;
			while (line[index] != '"')
				index++;
		}
		if (!is_whitespace(line[index]) && !in_word)
		{
			in_word = 1;
			nb++;
		}
		else if (is_whitespace(line[index]))
			in_word = 0;
		index++;
	}
	return (nb);
}

size_t	calculate_length(char *line, size_t index)
{
	size_t len;

	len = 0;
	while (!is_whitespace(line[index]) && line[index + 3])
	{
		if (line[index] == '"')
		{
			index++;
			len++;
			while (line[index] != '"')
			{
				len++;
				index++;
			}
		}
		index++;
		len++;
	}
	return (len);
}

char	**custom_split(t_rt *rt, char *line, size_t index)
{
	int		nb_custom_word;
	char	**tab;
	int		i;

	nb_custom_word = get_custom_words_number(line, index);
	tab = (char **)ft_memalloc((nb_custom_word + 1) * sizeof(char *));
	if (!tab)
		free_garbage(rt);
	garbage_collector(rt, tab);
	i = 0;
	while (nb_custom_word--)
	{
		while (is_whitespace(line[index]))
			index++;
		tab[i] = ft_strsub(line, index, calculate_length(line, index));
		index += calculate_length(line, index);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
