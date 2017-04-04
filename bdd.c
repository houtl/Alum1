/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bdd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 21:00:05 by luperez           #+#    #+#             */
/*   Updated: 2017/04/02 12:34:06 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

t_bdd	*new_bdd(void)
{
	t_bdd		*e;

	e = (t_bdd *)malloc(sizeof(t_bdd));
	if (!e)
		return (NULL);
	ft_bzero(e, sizeof(t_bdd));
	return (e);
}

t_bdd	*bdd(void)
{
	static int		i = 0;
	static t_bdd	*bdd;

	if (i == 0 && ++i)
		bdd = new_bdd();
	return (bdd);
}
