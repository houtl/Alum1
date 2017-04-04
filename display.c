/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 19:22:47 by luperez           #+#    #+#             */
/*   Updated: 2017/04/02 17:08:22 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	clear_screen(void)
{
	ft_putstr("[1;1H\e[2J[1;1H\e[2J\n");
}

int		choose_ia(int first)
{
	if (get_response("Do you want to play against THE IA ?"))
	{
		bdd()->ia = 1;
		if (get_response("Do you want to be an IA ?"))
			bdd()->ia = 3;
	}
	else
		bdd()->ia = 0;
	return (first);
}

int		starter(void)
{
	char	*rand;

	clear_screen();
	ft_putstr("\033[5;34;1mPress enter to start the game\033[0m");
	get_next_line(0, &rand);
	clear_screen();
	if (rand)
		free(rand);
	return (choose_ia((((int)rand) % 5) ? 1 : 2));
}

char	*question(int player_id, char *answer)
{
	ft_putstr((player_id == 1) ? "\033[34;1m" : "\033[31;1m");
	ft_putstr("Player ");
	ft_putnbr(player_id);
	ft_putstr(": How many matches do you want to pick ?\n");
	get_next_line(0, &answer);
	ft_putstr("\033[0m");
	return (answer);
}

void	win(int player_id)
{
	ft_putstr((player_id == 1) ? "\033[34;1m" : "\033[31;1m");
	if (bdd()->ia && player_id == 2)
		ft_putstr((bdd()->ia == 3) ? "IA2" : "IA");
	else
	{
		if (bdd()->ia == 3)
			ft_putstr("IA1");
		else
		{
			ft_putstr("Player ");
			ft_putnbr(player_id);
		}
	}
	ft_putstr(" WON!\033[0m\n");
}
