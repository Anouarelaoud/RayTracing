/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:41:07 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/09 23:28:08 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	free_garbage(t_rt *rt)
{
	t_garbage	*next;

	while (rt->garbage)
	{
		next = rt->garbage->next;
		free(rt->garbage->ptr);
		rt->garbage->ptr = NULL;
		free(rt->garbage);
		rt->garbage = next;
	}
	exit(EXIT_SUCCESS);
}

void	garbage_collector(t_rt *rt, void *ptr)
{
	t_garbage	*head;

	head = rt->garbage;
	while (rt->garbage)
		rt->garbage = rt->garbage->next;
	rt->garbage = (t_garbage *)malloc(sizeof(t_garbage));
	if (rt->garbage)
	{
		rt->garbage->ptr = ptr;
		rt->garbage->next = NULL;
	}
	else
		free_garbage(rt);
	rt->garbage = head;
}
