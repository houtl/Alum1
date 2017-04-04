/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 17:46:02 by luperez           #+#    #+#             */
/*   Updated: 2017/04/02 17:46:46 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static void	replay(int *map, char *str)
{
	free(map);
	if (get_response("\nDo you want to play again?"))
	{
		map = initmap(str);
		game_start(map, str);
	}
	else
		free(str);
}

int			*get_last_line(int *map)
{
	if (!map || !*map)
		return (0);
	while (*map)
		map++;
	return (map - 1);
}

int			is_valid(char *answer, int *map)
{
	int	rep;
	int	*last_line;

	rep = ft_atoi(answer);
	free(answer);
	if (rep < 1)
	{
		ft_putstr("Minimum required: 1 match\n");
		return (0);
	}
	if (rep > MAX_SUB)
	{
		ft_putstr("Maximum matches you can pick: ");
		ft_putnbr(MAX_SUB);
		ft_putchar('\n');
		return (0);
	}
	last_line = get_last_line(map);
	if (rep > *last_line)
	{
		ft_putendl("Not enough matches to withdraw that many!");
		return (0);
	}
	*last_line = *last_line - rep;
	return (rep);
}

void		turn(int player_id, int *map)
{
	char	*answer;
	int		valid;

	print_map(map);
	if (bdd()->ia && (player_id == 2 || bdd()->ia == 3))
		return (ia_turn(player_id, map));
	valid = 0;
	while (!valid)
	{
		answer = question(player_id, answer);
		valid = is_valid(answer, map);
	}
}

void		game_start(int *map, char *str)
{
	int		*last_line;
	int		player_id;

	player_id = starter();
	while (1)
	{
		turn(player_id, map);
		player_id = (player_id == 2) ? 1 : 2;
		last_line = get_last_line(map);
		if (!last_line || !*last_line)
			break ;
	}
	win(player_id);
	replay(map, str);
}
