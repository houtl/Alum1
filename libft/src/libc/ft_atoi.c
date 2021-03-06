/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:42:18 by thou              #+#    #+#             */
/*   Updated: 2016/11/14 15:16:32 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*c;
	int		i;
	int		j;

	i = 0;
	j = 1;
	c = (char*)str;
	while (*c == ' ' || *c == '\n' || *c == '\t'
			|| *c == '\f' || *c == '\v' || *c == '\r')
		c++;
	if (*c == '-')
		j = -1;
	if (*c == '+' || *c == '-')
		c++;
	while (*c >= '0' && *c <= '9')
	{
		i = i * 10 + *c - '0';
		c++;
	}
	i = i * j;
	return (i);
}
