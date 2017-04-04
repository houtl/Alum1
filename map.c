/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:26:39 by luperez           #+#    #+#             */
/*   Updated: 2017/04/02 16:54:07 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		line_checker(char *line, char **file_content)
{
	int		value;
	char	*trimed_line;

	trimed_line = ft_strtrim(line);
	free(line);
	if (!trimed_line)
		return (-1);
	if (*trimed_line == 0)
	{
		free(trimed_line);
		return (0);
	}
	value = ft_atoi(trimed_line);
	if (value < 1)
	{
		free(trimed_line);
		return ((value < 0) ? -1 : 0);
	}
	trimed_line = ft_strjoinfree2(ft_strdup(";"), trimed_line);
	*file_content = ft_strjoinfree2(*file_content, trimed_line);
	return ((!*file_content || value < 1 || value > 10000) ? -1 : 1);
}

char	*ft_mapchecker(int fd)
{
	char	*line;
	char	*file_content;
	int		f;

	file_content = ft_strdup("");
	f = 1;
	while (f == 1)
	{
		if (get_next_line(fd, &line) < 1)
			break ;
		f = line_checker(line, &file_content);
		if (f == -1)
		{
			if (file_content)
				free(file_content);
			return (NULL);
		}
	}
	return (file_content);
}

int		*initmap(char *str)
{
	char	**tmp;
	int		*map;
	int		i;

	tmp = ft_strsplit(str + 1, ';');
	i = -1;
	while (tmp[++i])
		;
	map = (int*)malloc(sizeof(int) * i + 1);
	i = -1;
	while (tmp[++i])
	{
		map[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
	}
	free(tmp);
	map[i] = 0;
	return (map);
}

void	print_map(int *map)
{
	int nbbar;

	ft_putstr("\033[33;1m");
	while (map && *map)
	{
		nbbar = *map;
		while (nbbar--)
			ft_putchar('|');
		ft_putchar('\n');
		map++;
	}
	ft_putstr("\033[0m");
}
