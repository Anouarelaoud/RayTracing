/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <aait-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 03:54:46 by slaanani          #+#    #+#             */
/*   Updated: 2020/11/12 18:19:00 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	*allocate(t_rt *rt, size_t size)
{
	void *ptr;

	if (!(ptr = (size_t *)ft_memalloc(size * sizeof(size_t))))
		free_garbage(rt);
	garbage_collector(rt, ptr);
	return (ptr);
}
