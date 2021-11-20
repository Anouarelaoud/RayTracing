/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 22:43:10 by mderri            #+#    #+#             */
/*   Updated: 2020/11/08 19:46:56 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	divi(long n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*tab;
	size_t	siz;
	long	nb;
	int		x;

	x = 0;
	nb = n;
	siz = divi(nb);
	if (nb < 0)
		x++;
	if (!(tab = ft_strnew(siz + x)))
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		tab[0] = '-';
	}
	while (siz)
	{
		tab[siz + x - 1] = '0' + (nb % 10);
		nb = nb / 10;
		siz--;
	}
	return (tab);
}
