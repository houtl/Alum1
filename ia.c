/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 22:51:28 by luperez           #+#    #+#             */
/*   Updated: 2017/04/02 18:26:20 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int			count_all_alu(int *map)
{
	int		total;

	total = 0;
	while (map && *map)
		total += *map++;
	return (total);
}

static int	lose_line(int last)
{
	return (((last % 4) == 0) ? 1 : (last % 4));
}

static int	win_line(int last)
{
	if (last > 1)
		return ((((last - 1) % 4) == 0) ? 1 : ((last - 1) % 4));
	else
		return (1);
}

int			better(int *map, int last)
{
	int		line1;
	int		tmp;

	tmp = -1;
	while (map[++tmp])
		;
	line1 = 0;
	tmp -= 2;
	while (tmp >= 0 && (map[tmp] == 1 || ((map[tmp] - 1) % 4 == 0)))
	{
		line1 += 1;
		tmp--;
	}
	if (line1 % 2 == 1)
		return (lose_line(last));
	else
		return (win_line(last));
}

void		ia_turn(int player_id, int *map)
{
	int		*last_line;
	int		choice;

	last_line = get_last_line(map);
	choice = better(map, *last_line);
	if (bdd()->ia == 3)
	{
		ft_putstr((player_id == 1) ? "\033[34;1mIA" : "\033[31;1mIA");
		ft_putnbr(player_id);
		ft_putendl("'s turn:\033[31;1m");
	}
	else
		ft_putendl("\033[31;1mIA's turn:\033[31;1m");
	if (is_valid(ft_itoa_base(choice, 10), map) == 0)
		ft_putendl("\033[31;1mIA spoiled\033[31;1m");
	else
	{
		ft_putnbr(choice);
		ft_putstr("\n");
	}
}
