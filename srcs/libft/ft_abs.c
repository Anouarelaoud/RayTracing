/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:24:49 by mderri            #+#    #+#             */
/*   Updated: 2019/02/10 19:24:52 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	else
		return (i);
}