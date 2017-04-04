/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 11:44:42 by thou              #+#    #+#             */
/*   Updated: 2017/04/02 16:34:51 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*str;
	int		*map;

	if (ac == 1)
		str = ft_mapchecker(0);
	else
	{
		fd = open(av[1], O_RDONLY);
		str = ft_mapchecker(fd);
	}
	if (!str || !*str)
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	map = initmap(str);
	game_start(map, str);
	free(bdd());
	return (0);
}
